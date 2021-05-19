#include <stdexcept>
#include <string>
#include "array.h"

int columns;
int rows;
Cell** sheet;

float Array::sum(Identifier *identifiers, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        float data = getNumberFromSheet(identifiers[i]);
        sum += data;
    }
    return sum;
}

float Array::subtract(Identifier minued, Identifier subtrahend) {
    float first = getNumberFromSheet(minued);
    float second = getNumberFromSheet(subtrahend);
    return first - second;
}

float Array::divide(Identifier divisor, Identifier dividend) {
    float first = getNumberFromSheet(divisor);
    float second = getNumberFromSheet(dividend);
    if (second != 0) {
        return first / second;
    }
    else {
        throw std::runtime_error("Math alert: Attempted to divide by Zero\n");
    }
}

float Array::multiplication(Identifier *identifiers, int length) {
    float multip = 0;
    for (int i = 0; i < length; i++) {
        float data = getNumberFromSheet(identifiers[i]);
        if (i == 0){
            multip = data;
        }
        else{
            multip *= data;
        }
    }
    return multip;
}

float Array::average(Identifier *identifiers, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        float data = getNumberFromSheet(identifiers[i]);
        sum += data;
    }
    return sum / length;
}

void Array::changeValue(Identifier identifier, Cell value) {
        checkIdentifier(identifier);
        sheet[identifier.Column][identifier.Row] = value;
}

void Array::resizeSheet(int columns, int rows) {
    Cell** newSheet = new Cell*[columns];
    for(int i = 0; i < columns; i++) {
        newSheet[i] = new Cell[rows];
    }
    //Pass data
    for(int i = 0; i < sheetColumns; ++i) {
        for(int j = 0; j < sheetRows; ++j) {
            newSheet[i][j] = sheet[i][j];
        }
    }
    //delete old sheet from memory
    for(int i = 0; i < sheetColumns; ++i) {
        delete [] sheet[i];
    }
    delete [] sheet;
    // change sheets
    sheet = newSheet;
    sheetColumns = columns;
    sheetRows = rows;
}

float Array::getNumberFromSheet(Identifier identifier) {
    checkIdentifier(identifier);
    if (sheet[identifier.Column][identifier.Row].areDecimalOperationsAllowed) {
        return sheet[identifier.Column][identifier.Row].getDecimalValue();
    }
    else {
        throw std::runtime_error("Cannot use text values in math operations");
    }
}

Cell Array::getCellFromSheet(Identifier identifier) {
    checkIdentifier(identifier);
    return sheet[identifier.Column][identifier.Row];
}

using namespace std;
void Array::saveDataToFile() {
    std::ofstream save("array.txt");
    save << to_string(sheetRows) << endl;
    save << to_string(sheetColumns) << endl;
    for(int i = 1; i <= sheetRows; ++i) {
        for(int x = 1; x <= sheetColumns; ++x) {
            Identifier id = Identifier(x, i);
            save << getCellFromSheet(id).getValue() << " ";
        }
        save << endl;
    }
    save.close();
}

void Array::loadDataFromFile() {
    ifstream infile("array.txt");
    string line;
    int columns = 0, rows = 0, i = 0;

    while (getline(infile, line)){
        if(i == 0){
            rows = stoi(line);
        }
        else if(i == 1){
            columns = stoi(line);
            resizeSheet(columns, rows);
        }
        else {
            istringstream iss(line);
            for (int x = 0; x < columns; x++){
                string val;
                iss >> val;
                sheet[x][i-2].changeValue(val);
            }
        }
        i++;
    }
}

void Array::checkIdentifier(Identifier identifier) {
    if (identifier.Column > sheetColumns && identifier.Row > sheetRows) {
        throw std::out_of_range(std::string("There is no cell at [" +
                                            std::to_string(identifier.Column) +
                                            "][" + std::to_string(identifier.Row) + "] in sheet. \n"));
    }
}

int Array::columns() const {
    return sheetColumns;
}

int Array::rows() const {
    return sheetRows;
}

std::string Array::getNumberAsString(Identifier identifier) {
    float val = (getNumberFromSheet(identifier));
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << val;
    return stream.str();
}

int Array::getMaxLengthValue(int precision) {
    int max;
    string valueString;
    for(int i = 1; i <= sheetRows; ++i) {
        for(int x = 1; x <= sheetColumns; ++x) {
            Identifier id = Identifier(x, i);
            if (sheet[id.Column][id.Row].areDecimalOperationsAllowed){
                valueString = to_string_with_precision(getNumberFromSheet(id), precision);
                //valueString = getStringFromSheet(id);
            }
            else {
                valueString = getStringFromSheet(id);
            }
            int value = valueString.length();
            if(i == 1 && x == 1) {
                max = value;
            }
            if (max < value) {
                max = value;
            }
        };
        return max;
    }
}

template <typename T>
std::string Array::to_string_with_precision(const T a_value, const int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

std::string Array::getStringFromSheet(Identifier identifier) {
    return sheet[identifier.Column][identifier.Row].getValue();
}


