#define OWNEXCEL_ARRAY_H

#include "../Models/Identifier.h"

    /*
     * \brief This is a class handling all operations on sheet.
     */
class Array {
public:
    /*
     * \param this variable store actual number of columns in sheet
     */
    int sheetColumns;
    /*
     * \param this variable store actual number of rows in sheet
     */
    int sheetRows;
    /*
     * \param this variable store sheet using float array of arrays
     */
    float** sheet;
    /*
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
                sheet[i][j] = i;
    }
    /*
     * \brief func that return sum of values depends on each one position in sheet and returns result.
     */
    float sum(Identifier *identifiers, int length);
    /*
     * \brief func that subtract two values from sheet and returns result.
     */
    float subtract(Identifier minued, Identifier subtrahend);
    /*
     * \brief func that divide two values from sheet and returns result.
     */
    float divide(Identifier divisor, Identifier dividend);
    /*
     * \brief func that return multiplication of values depends on each one position in sheet and returns result.
     */
    float multiplication(Identifier *identifiers, int length);
    /*
     * \brief func that return average value of values depends on each one position in sheet and returns result.
     */
    float average(Identifier *identifiers, int length);
    /*
     * \brief func that change value single position in sheet and return true or false depends on result.
     */
    bool changeValue(Identifier identifier, float value);
    /*
     * \brief func that resize sheet with no data lose.
     */
    bool resizeSheet(int columns, int lines);
    /*
     * \brief func that return single value from sheet depends on it position.
     */
    float getNumberFromSheet(Identifier identifier);
    /*
     * \brief func that write number to sheet on concrete position.
     */
    bool writeNumberToSheet(float number, int column, int row);
    /*
     * \brief func that save data from array to file (NOT IMPLEMENTED)
     */
    bool saveDataToFile();
    /*
     * \brief func that load data from file (NOT IMPLEMENTED)
     */
    bool LoadDataFromFile();
};