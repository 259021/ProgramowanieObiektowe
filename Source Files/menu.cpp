#include "menu.h"
#include "iostream"
using namespace std;

Operations Menu::showFunctions() {
    cout << "Press + to invoke adding cells" << endl;
    cout << "Press - to invoke subtraction cells" << endl;
    cout << "Press * to invoke multiplication cells" << endl;
    cout << "Press / to invoke dividing cells" << endl;
    cout << "Press = to change cell values" << endl;
    cout << "Press s save sheet to file" << endl;
    cout << "Press l sheet from file" << endl;
    cout << "Press F3 to invoke average value of cells" << endl;
    cout << "Press F2 to resize sheet" << endl;
    cout << "Press F1 exit" << endl;
    char c = getchar();
    switch (c) {
        case '+':
            return  Operations::sum;
        case '-':
            return  Operations::divide;
        case '*':
            return  Operations::multiplication;
        case '/':
            return  Operations::divide;
        case -122:
            return  Operations::exitCode;
        case -120:
            return  Operations::resize;
        case -99:
            return  Operations::average;
        case 's':
            return Operations::save;
        case 'l':
            return Operations::load;
        default:
            return Operations::noAction;
    };
};

Identifier Menu::getCell() {
    int col = 1;
    int row = 1;
    bool properValue = false;
    while(!properValue){
        cout << "Which cell dou you want to select to this operation? " << endl;
        try {
            cout << "column: ";
            cin >> col;
            cout << "row: ";
            cin >> row;
            properValue = true;
        }
        catch(exception) {
            cout << "Write proper cell value!";
            properValue = false;
        };
    }
    Identifier id = Identifier(col, row);
    return id;
};

int Menu::HowManyCells() {
    int count = 0;
    bool properValue = false;
    while(!properValue){
        cout << "How many cells you want to use?" << endl;
        try {
            cout << "count: ";
            cin >> count;
            properValue = true;
        }
        catch(exception) {
            cout << "Write proper value!";
            properValue = false;
        };
    }
    return count;
}

Identifier Menu::WhereToSave() {
    int col = 1;
    int row = 1;
    bool properValue = false;
    while(!properValue){
        cout << "Where do you want to save your data? " << endl;
        try {
            cout << "column:";
            cin >> col;
            cout << "row: ";
            cin >> row;
            properValue = true;
        }
        catch(exception) {
            cout << "Write proper cell value!";
            properValue = false;
        };
    }
    Identifier id = Identifier(col, row);
    return id;
}


