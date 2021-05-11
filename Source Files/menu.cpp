#include <menu.h>


using namespace std;

Operations Menu::showFunctions() {
    cout << "Press + to invoke adding cells\n";
    cout << "Press - to invoke subtraction cells\n";
    cout << "Press * to invoke multiplication cells\n";
    cout << "Press / to invoke dividing cells\n";
    cout << "Press = to change cell values\n";
    cout << "Press s save sheet to file\n";
    cout << "Press l sheet from file\n";
    cout << "Press F3 to invoke average value of cells\n";
    cout << "Press F2 to resize sheet\n";;
    cout << "Press F1 exit";

    int c = getch();
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


float Menu::getNumber(const string& message) {
    float count = 0;
    bool properValue = false;
    while(!properValue){
        cout << message << endl;
        try {
            cout << "count: ";
            cin >> count;
            properValue = true;
        }
        catch(...) {
            error("Write proper value!");
            properValue = false;
        };
    }
    return count;
}

Identifier Menu::getIdentifier(const string& message) {
    int col = 1;
    int row = 1;
    bool properValue = false;
    while(!properValue){
        cout << message << endl;
        try {
            cout << "column:";
            cin >> col;
            cout << "row: ";
            cin >> row;
            properValue = true;
        }
        catch(...) {
            cout << "Write proper cell value!";
            properValue = false;
        };
    }
    Identifier id = Identifier(col, row);
    return id;
}

void Menu::message(const string& message) {
    cout << message << endl;
}

void Menu::error(const string& message) {
    cout << "\033[1;31m" << message << "\033[0m\n";
}
int Menu::getch() {
        struct termios oldt{},
                newt{};
        int            ch;
        tcgetattr( STDIN_FILENO, &oldt );
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
        return ch;
}


