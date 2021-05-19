#include "array_display.h"

using namespace std;

void ArrayDisplay::Display(Array *arr) {
    int precision = 2;
    int max = arr->getMaxLengthValue(precision);
    int cellWidth = (max + 4);

    for (int j = 0; j <= cellWidth*arr->columns()*1.35; ++j) {
        cout << "―";
    }
    cout << endl;

    for(int i = 0; i <= arr->rows(); ++i) {
        if(i != 0){
            cout << "│" << "\033[1;32m" << setw(4) << i << "\033[0m";
        }
        for(int x = 0; x <= arr->columns(); ++x) {
            if (i == 0 && x == 0) {
                cout << "│" << "\033[1;32m" << setw(4) << "Lp." << "\033[0m";
            }
            if (i == 0 && x != 0 && x != arr->columns()) {
                cout << "│" << "\033[1;32m" << setw(cellWidth+1)  << x << setw(cellWidth/2) << "\033[0m" ;
            }
            if (i == 0 && x != 0 && x == arr->columns()) {
                cout << "│" << "\033[1;32m" << setw(cellWidth+1)  << x << setw(cellWidth/2) << "\033[0m" << "│";
            }

            if(i != 0 && x!=0){
                Identifier id = Identifier(x, i);
                Cell cell = arr->getCellFromSheet(id);
                string value;
                if(cell.areDecimalOperationsAllowed) {
                    value = to_string_with_precision(cell.getDecimalValue(), precision);
                } else {
                    value = cell.getValue();
                }

                if (x != arr->columns()){
                    cout << "│" << setw(cellWidth) << value << setw(cellWidth/2);
                }
                else {
                    cout << "│" << setw(cellWidth) << value << setw(cellWidth/2) << "│";

                }
            }
        }
        cout << endl;
    }
    for (int j = 0; j <= cellWidth*arr->columns()*1.35; ++j) {
        cout << "―";
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