//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_DECIMALCELL_H
#define OWNEXCEL_DECIMALCELL_H
#include "Cell.h"
#include "CellValue.h"
#include <utility>

class DecimalCell: public Cell {
private:
    CellValue value;

public:
    void changeValue(std::string val) override;
    CellValue getValue() override;

    explicit DecimalCell(float val) : value(val) {

    }

    DecimalCell(): value(0) {

    };
};

#endif //OWNEXCEL_DECIMALCELL_H
