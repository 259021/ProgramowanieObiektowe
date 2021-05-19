#ifndef OWNEXCEL_ARRAY_H
#define OWNEXCEL_ARRAY_H

#include "../Models/Identifier.h"
#include "../Models/DecimalCell.h"
#include "../Models/TextCell.h"
#include "fstream"
#include "iostream"
#include "sstream"
#include <iomanip>
#include <cstdlib>
    /**
     * \brief This is a class handling all operations on sheet.
     */
class Array {
private:
    /**
    * \param this variable store actual number of columns in sheet
    */
    int sheetColumns;
    /**
     * \param this variable store actual number of rows in sheet
     */
    int sheetRows;
    /**
     * \param this variable store sheet using float array of arrays
     */
    Cell** sheet;
public:
    /**
     * \brief Constructor of class
     *
     * Just in time of creating array object constructor configure sheet variable to proper value of rows and columns.
     * Construction also configure columns and rows properties.
     */
    Array(int columns, int rows){
        sheetColumns = columns;
        sheetRows = rows;
        sheet = new Cell*[columns];
        for(int i = 0; i < columns; i++) {
            sheet[i] = new Cell[rows];
    }

        //pass test data
        for(int i = 0; i < columns; ++i)
            for(int j = 0; j < rows; ++j) {
                DecimalCell cell = DecimalCell("0");
                sheet[i][j] = cell;
            }

    }
    Array(){
        sheetColumns = 4;
        sheetRows = 4;
        sheet = new Cell*[sheetColumns];
        for(int i = 0; i < sheetColumns; i++) {
            sheet[i] = new Cell[sheetRows];
        }

        //pass test data
        for(int i = 0; i < sheetColumns; ++i)
            for(int j = 0; j < sheetRows; ++j)
                sheet[i][j] = Cell(true);
    }

    /**
     *
     * @return numbers of columns
     */
    int columns() const;
    /**
     *
     * @return number of rows
     */
    int rows() const;
    /**
     * \brief func that return sum of values depends on each one position in sheet and returns result.
     * @param[in] identifiers - array that holds position of cells.
     * @param[in] length - holds length of identifiers array
     * @return - float value or exception
     */
    float sum(Identifier *identifiers, int length);
    /**
     * \brief func that subtract two values from sheet and returns result.
     * @param[in] minued - first number identifier
     * @param[in] subtrahend - second number identifier
     * @return - float value or exception
     */
    float subtract(Identifier minued, Identifier subtrahend);
    /**
     * \brief func that divide two values from sheet and returns result.
     * @param[in] divisor - first number identifier
     * @param[in] dividend - second number identifier
     * @return - float value or exception.
     */
    float divide(Identifier divisor, Identifier dividend);
    /**
     * \brief func that return multiplication of values depends on each one position in sheet and returns result.
     * @param[in] identifiers - array that holds position of cells.
     * @param[in] length - length of array.
     * @return - float value
     */
    float multiplication(Identifier *identifiers, int length);
    /**
     * \brief func that return average value of values depends on each one position in sheet and returns result.
     * @param[in] identifiers - array that holds position of cells.
     * @param[in] length - length of array.
     * @return - float value
     */
    float average(Identifier *identifiers, int length);
    /**
     * \brief func that change value single position in sheet and return true or false depends on result.
     * @param[in] identifier - position of cell that gonna be changed.
     * @param[in] value - float value to write up.
     * @return - nothing or exception
     */
    void changeValue(Identifier identifier, Cell value);
    /**
     * \brief func that resize sheet with no data lose.
     * @param[in] columns - new numbers of columns in sheet.
     * @param[in] rows - new numbers of rows in sheet.
     * @return return nothing or exception
     */
    void resizeSheet(int columns, int rows);
    /**
     * \brief func that return single value from sheet depends on it position.
     * @param identifier - position of cell that value func gonna return.
     * @return return float or exception
     */
    float getNumberFromSheet(Identifier identifier);
    Cell getCellFromSheet(Identifier identifier);
    /**
     * \brief func that return single value from sheet depends on it position.
     * @param identifier - position of cell that value func gonna return.
     * @return return string or exception
     */
    std::string getStringFromSheet(Identifier identifier);
    /**
     * \brief func that save data from array to file (NOT IMPLEMENTED)
     * @return - nothing
     */
    void saveDataToFile();
    /**
     * \brief func that load data from file (NOT IMPLEMENTED)
     * @return - nothing
     */
    void loadDataFromFile();
     /**
     * func search max value stored in sheet.
     * @param precision - precision to round off
     * @return - max value as float
     */
    int getMaxLengthValue(int precision);

    /**
     * func search max value stored in sheet.
     * @param n - precision to round off
     * @param a_value - value to round off
     * @return - rounded value as string
     */
    template <typename T>
    std::string to_string_with_precision(const T a_value, const int n);
private:
    /**
     * func that check if identifier isn't out of bounds.
     * @param identifier - holds cell position.
     * @return - nothing or exception
     */
    void checkIdentifier(Identifier identifier) const;


};
#endif