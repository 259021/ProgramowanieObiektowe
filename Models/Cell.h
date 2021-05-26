//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_CELL_H
#define OWNEXCEL_CELL_H
#include "string"
#include "CellValue.h"

class Cell {
/*
     * /brief This model represent single cell in sheet
     *
     */
protected:
    /**
    * \param this variable holds value as string
    */
    CellValue Value;
public:

    Cell(std::string val) : Value(val) {

    }
    Cell(float val): Value(val) {

    }

    Cell(): Value(0) {

    }

    /**
     * func that change value
     * @param value - param that hold value
     * @return - void
     */
    virtual void changeValue(std::string val) = 0;
    /**
     * func that change value
     * @param value - param that hold value
     * @return - void
     */
    virtual void changeValue(float val) = 0;

    /**
      * func that return value as string
      * @return - string value
      */
    virtual CellValue getValue() = 0;

    virtual void changeValueCell(CellValue val) = 0;
};




#endif //OWNEXCEL_CELL_H
