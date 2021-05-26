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
    void changeValue(std::string value) override;
    void changeValue(float val) override;
    CellValue getValue() override;


    DecimalCell(float val) : value(val) {
    }

    DecimalCell(): value(0) {

    };

    void changeValueCell(CellValue val) override;
};

#endif //OWNEXCEL_DECIMALCELL_H
