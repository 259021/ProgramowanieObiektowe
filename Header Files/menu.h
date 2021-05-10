#define OWNEXCEL_MENU_H
#include <iostream>
#include "../Models/Identifier.h"

enum Operations {sum, subtraction ,divide ,multiplication ,resize ,exitCode ,changeValue ,noAction, average, load, save};

class Menu {
public:
    Operations showFunctions();
    Identifier getCell();
    int HowManyCells();
    Identifier WhereToSave();
};