//
// Created by osboxes on 5/18/21.
//

#include "DecimalCell.h"

CellValue DecimalCell::getValue() {
    return value;
}

void DecimalCell::changeValue(std::string val) {
    value = CellValue(std::stof(val));
}
