//
// Created by osboxes on 5/18/21.
//

#include "TextCell.h"

void TextCell::changeValue(std::string val) {
    TextCell::value = CellValue(val);
}

CellValue TextCell::getValue() {
    return value;
}

void TextCell::changeValue(float val) {
    //MARK: - Not implemented -
}

