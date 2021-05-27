//
// Created by Patryk Ogonowski on 25/05/2021.
//

#ifndef OWNEXCEL_CELLVALUE_H
#define OWNEXCEL_CELLVALUE_H


#include "iostream"
    /*
    * /brief This model holds single cell value
    *
    *
    */
class CellValue{
private:
    /**
    * \param this variable holds value as string
    */
    std::string textValue;
    /**
    * \param this variable holds value as float
    */
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

    /**
     * func check if Cell value is string or decimal
     * @return - bool statement
     */
    bool areDecimalOperationsAllowed();
    /**
     * func that return float type value
     * @return - float value
     */
    float getDecimalValue();
    /**
    * func that return string type value
    * @return - string value
    */
    std::string getTextValue();
};


#endif //OWNEXCEL_CELLVALUE_H