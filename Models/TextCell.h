//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_TEXTCELL_H
#define OWNEXCEL_TEXTCELL_H
#include "Cell.h"

class TextCell: public Cell {
private:
    CellValue value;

public:
    void changeValue(std::string val) override;
    CellValue getValue() override;

    explicit TextCell(const std::string& val) : value(val) {

    }
};


#endif //OWNEXCEL_TEXTCELL_H
