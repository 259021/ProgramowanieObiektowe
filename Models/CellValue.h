//
// Created by Patryk Ogonowski on 25/05/2021.
//

#ifndef OWNEXCEL_CELLVALUE_H
#define OWNEXCEL_CELLVALUE_H


#include "iostream"

class CellValue{
private:
    std::string textValue;
    float decimalValue;
public:
    CellValue(float value){
        decimalValue = value;
        textValue;
    }
    CellValue(const std::string value){
        textValue = value;
    }
    CellValue() {
        decimalValue = 0;
        textValue = nullptr;
    }

    bool areDecimalOperationsAllowed();
    float getDecimalValue();
    std::string getTextValue();
};


#endif //OWNEXCEL_CELLVALUE_H