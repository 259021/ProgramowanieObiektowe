//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_DECIMALCELL_H
#define OWNEXCEL_DECIMALCELL_H
#include "Cell.h"

#include <utility>

class DecimalCell: public Cell {
public:
    DecimalCell(std::string value) {
        Cell::areDecimalOperationsAllowed = true;
        Cell::Value = std::move(value);
    }
};


#endif //OWNEXCEL_DECIMALCELL_H
