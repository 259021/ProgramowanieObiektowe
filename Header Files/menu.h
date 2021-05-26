#ifndef OWNEXCEL_MENU_H
#define OWNEXCEL_MENU_H
#include "iostream"
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include "../Models/Identifier.h"
#include "../Models/Cell.h"
#include "../Models/DecimalCell.h"
#include "../Models/TextCell.h"
    /**
   * \brief This is a enum that hold response from user.
   */
enum Operations {sum, subtraction ,divide ,multiplication ,resize ,exitCode ,changeValue ,noAction, average, load, save};

   /**
   * \brief This is a class handling menu operations
   */
class Menu {
public:
    /**
     * \brief func that get from user selected operation.
     * @return return operation enum
     */
    static Operations showFunctions();
    /**
     * \brief func that get cell identifier from user.
     * @param[in] message - message to user.
     * @return return Identifier of cell
     */
    static Identifier getIdentifier(const std::string& message);
    /**
    * \brief func that get number from user.
    * @param[in] message - message to user.
    * @return return float value
    */
    static float getNumber(const std::string& message);

    /**
    * \brief func that get string from user.
    * @param[in] message - message to user.
    * @return return float value
    */
    static CellValue getCell(const std::string& message);

    /**
    * \brief func that send message to user.
    * @param[in] message - message to user.
    * @return return void
    */
    static void message(const std::string& message);
    /**
    * \brief func that send alert message to user.
    * @param[in] message - message to user.
    * @return return void
    */
    static void alert(const std::string& message);
    /**
    * \brief func that getch char without waiting for enter
    * source: https://cboard.cprogramming.com/faq-board/27714-faq-there-getch-conio-equivalent-linux-unix.html
    * @return return int value of char
    */
    static int getch();
    /**
    * \brief func that clear console
    * @return void
    */
    static void clear();
};
#endif