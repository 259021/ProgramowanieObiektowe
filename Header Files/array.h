#ifndef OWNEXCEL_ARRAY_H
#define OWNEXCEL_ARRAY_H

#include "../Models/Identifier.h"
#include "fstream"
#include "iostream"
#include "sstream"
#include <iomanip>
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
    float** sheet;
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
        sheet = new float*[columns];
        for(int i = 0; i < columns; i++) {
            sheet[i] = new float[rows];
        }

        //pass test data
        for(int i = 0; i < columns; ++i)
            for(int j = 0; j < rows; ++j)
                sheet[i][j] = 0;
    }
    Array(){
        sheetColumns = 4;
        sheetRows = 4;
        sheet = new float*[sheetColumns];
        for(int i = 0; i < sheetColumns; i++) {
            sheet[i] = new float[sheetRows];
        }

        //pass test data
        for(int i = 0; i < sheetColumns; ++i)
            for(int j = 0; j < sheetRows; ++j)
                sheet[i][j] = 0;
    }

    /**
     *
     * @return numbers of columns
     */
    int columns();
    /**
     *
     * @return number of rows
     */
    int rows();
    /**
     *
     * @return numbers in sheet in single dimension array of chars
     */
    char* sheetAsChars();
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
    void changeValue(Identifier identifier, float value);
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
     * @return return nothing or exception
     */
    float getNumberFromSheet(Identifier identifier);
    /**
     *
     * @param identifier - position of cell that value func gonna return.
     * @return number as string value
     */
    std::string getNumberAsString(Identifier identifier);
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
     * @return - max value as float
     */
    float getMaxValue();

private:
    /**
     * func that check if identifier isn't out of bounds.
     * @param identifier - holds cell position.
     * @return - nothing or exception
     */
    void checkIdentifier(Identifier identifier);
};
#endif