#ifndef OWNEXCEL_OPERATION_HANDLER_H
#define OWNEXCEL_OPERATION_HANDLER_H
#include "array.h"
#include "menu.h"
#include "vector"


/**
   * \brief This is a class handling menu operations
   */
class OperationHandler{
public:
    /**
     * \brief static func that handling decimal operations.
     * @param[in,out] arr - 2D array that holds sheet.
     * @param[in] operation - enum instance that holds user operation.
     * @return - -1 if exit, 0 if everything is okey.
     */
    static int decimalOperation(Operations operation, Array *arr);
};


#endif //OWNEXCEL_OPERATION_HANDLER_H
