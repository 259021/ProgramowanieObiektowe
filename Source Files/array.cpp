#include <exception>
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
        return 0; // TODO: maybe some error handling?
    }
}

float Array::multiplication(Identifier *identifiers, int length) {
    float multip = 0;
    for (int i = 0; i < length; i++) {
        float data = getNumberFromSheet(identifiers[i]);
        multip *= data;
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

bool Array::changeValue(Identifier identifier, float value) {
    try {
        sheet[identifier.column][identifier.row] = value;
    } catch (std::exception & exception) {
        return false;
    }
    return true;
}

bool Array::resizeSheet(int columns, int rows) {
    //TODO: Add Error handling
    //create new Sheet
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
        delete [] sheet;
    }
    // change sheets
    sheet = newSheet;
    return true;
}

float Array::getNumberFromSheet(Identifier identifier) {
    float val;
    try {
        val = sheet[identifier.column][identifier.row];
    } catch(std::exception & exception) {
        return 0;
    }
    return val;
}

bool Array::writeNumberToSheet(float number, int column, int row) {
    try {
        sheet[column][row] = number;
    } catch(std::exception & exception) {
      return false;
    }
    return true;
}

bool Array::saveDataToFile() {
    return false;
}

bool Array::LoadDataFromFile() {
    return false;
}


