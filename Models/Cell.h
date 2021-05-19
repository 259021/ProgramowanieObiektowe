//
// Created by osboxes on 5/18/21.
//

#ifndef OWNEXCEL_CELL_H
#define OWNEXCEL_CELL_H
#include "string"

class Cell {
/*
     * /brief This model represent single cell in sheet
     *
     */
protected:
    /**
    * \param this variable holds value as string
    */
    std::string Value;
    /*

    */
public:
    Cell(bool decimal){
        areDecimalOperationsAllowed = decimal;
    }
    Cell(){

    }
    /**
    * \param this variable tells us if this concrete cell holds decimal value or text value
    */
    bool areDecimalOperationsAllowed{};
    /**
     * func that change value
     * @param value - param that hold value
     * @return - void
     */
    virtual void changeValue(std::string value);
    /**
      * func that return value as string
      * @return - string value
      */
    virtual std::string getValue();
    /**
     * func that return value as float
     * @return - float value
     */
    virtual float getDecimalValue();
};




#endif //OWNEXCEL_CELL_H
