//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_CELL_H
#define OWNEXCEL_CELL_H
#include "string"
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

class Cell {
/*
     * /brief This model represent single cell in sheet
     *
     */
protected:
    int Column{};
    int Row{};
    std::string Value;
    /*

    */
public:
    Cell(int column, int row, bool decimal){
        Column = column;
        Row = row;
        areDecimalOperationsAllowed = decimal;
    }
    Cell() {
    }

    bool areDecimalOperationsAllowed{};
    virtual void changeValue(std::string value);
    virtual std::string getValue();
    virtual float getDecimalValue();
};




#endif //OWNEXCEL_CELL_H
