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
    * \param this variable holds value
    */
    CellValue Value;
public:
    
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
    virtual CellValue getValue() = 0;
};


#endif //OWNEXCEL_CELL_H
