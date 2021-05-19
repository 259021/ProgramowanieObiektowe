#ifndef OWNEXCEL_ARRAY_DISPLAY_H
#define OWNEXCEL_ARRAY_DISPLAY_H
#include "array.h"
#include <iostream>
#include <iomanip>
#include <string>

    /**
    * \brief This is a class handling displaying sheet.
    */
class ArrayDisplay {
public:
    /**
     * \brief func that display sheet.
     * @param[in] Array - 2D array that holds sheet.
     * @return - void or exception
     */
    void Display(Array *arr);

    /**
      * func search max value stored in sheet.
      * @param n - precision to round off
      * @param a_value - value to round off
      * @return - rounded value as string
      */
    template <typename T>
    std::string to_string_with_precision(const T a_value, const int n = 6);
};
#endif