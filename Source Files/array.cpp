#include <stdexcept>
#include <string>
#include <utility>
#include "array.h"

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

void Array::changeValue(Identifier identifier, CellValue value) {
        checkIdentifier(identifier);
        if(value.areDecimalOperationsAllowed()){
            sheet[identifier.Column][identifier.Row] = new DecimalCell(value.getDecimalValue());
        } else {
            sheet[identifier.Column][identifier.Row] = new TextCell(value.getTextValue());
        }
}

void Array::resizeSheet(int columns, int rows) {
    Cell*** newSheet = new Cell **[columns];
    for(int i = 0; i < columns; i++) {
        newSheet[i] = new Cell*[rows];
    }
    //MARK: - Pass Data -
    for(int i = 0; i < columns; ++i) {
        for(int j = 0; j < rows; ++j) {
            newSheet[i][j] = new DecimalCell(0);
        }
    }
    if(columns > sheetColumns && rows > sheetRows) {
        for(int i = 0; i < sheetColumns; ++i) {
            for(int j = 0; j < sheetRows; ++j) {
                newSheet[i][j] = sheet[i][j];
            }
        }
    }
    if (columns > sheetColumns & rows < sheetRows) {
        for(int i = 0; i < sheetColumns; ++i) {
            for(int j = 0; j < rows; ++j) {
                newSheet[i][j] = sheet[i][j];
            }
        }
    }
    if (columns < sheetColumns & rows > sheetRows) {
        for(int i = 0; i < columns; ++i) {
            for(int j = 0; j < sheetRows; ++j) {
                newSheet[i][j] = sheet[i][j];
            }
        }
    }
    if(columns < sheetColumns & rows < sheetRows) {
        for(int i = 0; i < columns; ++i) {
            for(int j = 0; j < rows; ++j) {
                newSheet[i][j] = sheet[i][j];
            }
        }
    }
    //delete old sheet from memory
    for(int i = 0; i < sheetColumns; ++i) {
        delete [] sheet[i];
    }
    delete [] sheet;

    // change sheets
    sheetColumns = columns;
    sheetRows = rows;
    sheet = newSheet;

}

float Array::getNumberFromSheet(Identifier identifier) {
    checkIdentifier(identifier);
    if (sheet[identifier.Column][identifier.Row]->getValue().areDecimalOperationsAllowed()) {
        return sheet[identifier.Column][identifier.Row]->getValue().getDecimalValue();
    }
    else {
        throw std::runtime_error("Cannot use text values in math operations");
    }
}

CellValue Array::getCellFromSheet(Identifier identifier) {
    checkIdentifier(identifier);
    return sheet[identifier.Column][identifier.Row]->getValue();
}

using namespace std;
void Array::saveDataToFile() {
    std::ofstream save("array.txt");
    save << to_string(sheetRows) << endl;
    save << to_string(sheetColumns) << endl;
    for(int i = 1; i <= sheetRows; ++i) {
        for(int x = 1; x <= sheetColumns; ++x) {
            Identifier id = Identifier(x, i);
            save << getCellFromSheet(id).getTextValue() << " ";
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
                try {
                    float value = stof(val);
                    sheet[x][i-2] = new DecimalCell(value);
                }
                catch(...){
                    sheet[x][i-2] = new TextCell(val);
                }
            }
        }
        i++;
    }
}

void Array::checkIdentifier(Identifier identifier) const {
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

int Array::getMaxLengthValue(int precision) {
    int max;
    string valueString;
    for(int i = 1; i <= sheetRows; ++i) {
        for(int x = 1; x <= sheetColumns; ++x) {
            Identifier id = Identifier(x, i);
            if (sheet[id.Column][id.Row]->getValue().areDecimalOperationsAllowed()){
                valueString = to_string_with_precision(getNumberFromSheet(id), precision);
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
        }
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
    return sheet[identifier.Column][identifier.Row]->getValue().getTextValue();
}


