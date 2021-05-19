//
// Created by osboxes on 5/18/21.
//

#include "Cell.h"

#include <utility>


void Cell::changeValue(std::string value) {
    Value = std::move(value);
}

std::string Cell::getValue() {
    return Cell::Value;
}

float Cell::getDecimalValue() {
    return std::stof(Cell::getValue());
}
