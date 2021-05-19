#include <menu.h>


using namespace std;

Operations Menu::showFunctions() {
    cout << endl;
    cout << "Press \'+\' to invoke adding cells\n";
    cout << "Press \'-\' to invoke subtraction cells\n";
    cout << "Press \'*\' to invoke multiplication cells\n";
    cout << "Press \'/\' to invoke dividing cells\n";
    cout << "Press \'c\' to change cell values\n";
    cout << "Press \'s\' save sheet to file\n";
    cout << "Press \'l\' sheet from file\n";
    cout << "Press \'a\' to invoke average value of cells\n";
    cout << "Press \'r\' to resize sheet\n";;
    cout << "Press \'e\' exit";
    cout << endl;

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
        case 'c':
            return Operations::changeValue;
        case 'e':
            return  Operations::exitCode;
        case 'r':
            return  Operations::resize;
        case 'a':
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
            alert("Write proper value!");
            properValue = false;
        };
    }
    return count;
}

Cell Menu::getCell(const string& message) {
    string value = "0";

        cout << message << endl;
        try {
            cout << "count: ";
            cin >> value;
            float test = stof(value);
            DecimalCell cell = DecimalCell(value);
            return cell;
        }
        catch(...) {
            TextCell cell = TextCell(value);
            return cell;
        };
}

Identifier Menu::getIdentifier(const string& message) {
    int col = 1;
    int row = 1;
    bool properValue = false;
    while(!properValue){
        cout << message << endl;
        try {
            cout << "column: ";
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

void Menu::alert(const string& message) {
    cout << "\033[1;31m" << message << "\033[0m\n";
    sleep(2);
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


void Menu::clear() {
    system("clear");
}
