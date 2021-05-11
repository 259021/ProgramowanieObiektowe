#include "array_display.h"

using namespace std;

void ArrayDisplay::Display(Array arr) {
    int precision = 2;
    string max = to_string_with_precision(arr.getMaxValue(), precision);
    int cellWidth = (max.length() + 4);


    for(int i = 0; i <= arr.rows(); ++i) {
        if(i != 0){
            cout << "\033[1;32m" << setw(4) << i << "\033[0m";
        }
        for(int x = 1; x <= arr.columns(); ++x) {
            if (i == 0 && x == 1) {
                cout << "\033[1;32m" << setw(4) << "Lp." << "\033[0m";
            }
            if (i == 0 && x != 1) {
                cout << "|" << setw(cellWidth) << x-1 << setw(cellWidth/2);
            }
            if(i != 0){
                Identifier id = Identifier(x, i);
                //= std::to_string(arr.getNumberFromSheet(id));
                string value = to_string_with_precision(arr.getNumberFromSheet(id), precision);
                cout << "|" << setw(cellWidth) << value << setw(cellWidth/2);
            }
        }
        cout << endl;
    }
}


template <typename T>
std::string ArrayDisplay::to_string_with_precision(const T a_value, const int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}