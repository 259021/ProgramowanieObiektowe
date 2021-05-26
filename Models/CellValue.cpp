//
// Created by Patryk Ogonowski on 25/05/2021.
//

#include "CellValue.h"

bool CellValue::areDecimalOperationsAllowed() {
    if(textValue.empty()){
        return true;
    }
    return false;
}

float CellValue::getDecimalValue() {
    if(areDecimalOperationsAllowed()) {
      return decimalValue;
    } else {
        throw std::runtime_error("Cannot get value of text Cell");
    }
}

std::string CellValue::getTextValue() {
    if(!areDecimalOperationsAllowed()){
        return textValue;
    } else {
      return std::to_string(decimalValue);
    }

}
