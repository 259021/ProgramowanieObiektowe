#include <stdexcept>
#include <string>
#include "array.h"

int columns;
int rows;
float** sheet;

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

void Array::changeValue(Identifier identifier, float value) {
        checkIdentifier(identifier);
        sheet[identifier.Column][identifier.Row] = value;
}

void Array::resizeSheet(int columns, int rows) {
    //TODO: Resize doesnt work
    float** newSheet = new float*[columns];
    for(int i = 0; i < columns; i++) {
        newSheet[i] = new float[rows];
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
            save << to_string(getNumberFromSheet(id)) << " ";
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
                sheet[x][i-2] = stof(val);
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

int Array::columns() {
    return sheetColumns;
}

int Array::rows() {
    return sheetRows;
}

std::string Array::getNumberAsString(Identifier identifier) {
    float val = (getNumberFromSheet(identifier));
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << val;
    return stream.str();
}

float Array::getMaxValue() {
    float max;
    for(int i = 1; i <= sheetRows; ++i) {
        for(int x = 1; x <= sheetColumns; ++x) {
            Identifier id = Identifier(x, i);
            float value = getNumberFromSheet(id);
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


