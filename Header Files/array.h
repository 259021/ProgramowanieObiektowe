#define OWNEXCEL_ARRAY_H

#include "../Models/Identifier.h"

class Array {
public:

    int columns = 1;
    int lines = 1;
    float** sheet;
    Array(){
        sheet = new float*[columns];
        for(int i = 0; i < columns; i++) {
            sheet[i] = new float[lines];
        }
    }
    float Sum(Identifier *identifiers, int length);
    float subtract(Identifier minued, Identifier subtrahend);
    float divide(Identifier divisor, Identifier dividend);
    float multiplication(Identifier *identifiers, int length);
    float average(Identifier *identifiers, int length);
    float changeValue(Identifier identifier, float value);
    bool changeSheetSize(int columns, int lines);
};