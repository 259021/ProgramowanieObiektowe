//
// Created by osboxes on 5/18/21.
//

#include "DecimalCell.h"

void DecimalCell::changeValue(float val) {
value = CellValue(val);
}

CellValue DecimalCell::getValue() {
    return value;
}

void DecimalCell::changeValue(std::string value) {
    //MARK: - Not implemented -
}

void DecimalCell::changeValueCell(CellValue val) {
    value = val;
}
