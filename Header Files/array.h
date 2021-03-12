#define OWNEXCEL_ARRAY_H

#include "../Models/Identifier.h"

class Array {
public:
    int sheetColumns;
    int sheetRows;
    float** sheet;
    Array(int columns, int rows){
        sheetColumns = columns;
        sheetRows = rows;
        sheet = new float*[columns];
        for(int i = 0; i < columns; i++) {
            sheet[i] = new float[rows];
        }

        //pass test data
        for(int i = 0; i < columns; ++i)
            for(int j = 0; j < rows; ++j)
                sheet[i][j] = i;
    }
    //Calculate
    float sum(Identifier *identifiers, int length);
    float subtract(Identifier minued, Identifier subtrahend);
    float divide(Identifier divisor, Identifier dividend);
    float multiplication(Identifier *identifiers, int length);
    float average(Identifier *identifiers, int length);


    //Operations on sheet
    bool changeValue(Identifier identifier, float value);
    bool resizeSheet(int columns, int lines);
    float getNumberFromSheet(Identifier identifier);
    bool writeNumberToSheet(float number, int column, int row);
    bool saveDataToFile();
    bool LoadDataFromFile();


};