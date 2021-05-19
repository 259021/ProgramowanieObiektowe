//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_TEXTCELL_H
#define OWNEXCEL_TEXTCELL_H
#include "Cell.h"

class TextCell: public Cell {
public:
    TextCell(std::string value) {
        Cell::areDecimalOperationsAllowed = false;
        Cell::Value = std::move(value);
    }
};


#endif //OWNEXCEL_TEXTCELL_H
