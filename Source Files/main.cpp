#include "menu.h"
#include "array_display.h"
#include <vector>


int main() {
    Array arr = Array(14, 15);
    arr.loadDataFromFile();

    ArrayDisplay sheet = ArrayDisplay();
    sheet.Display(arr);

    Menu menu = Menu();
    Operations operation = menu.showFunctions();

    switch (operation) {
        case sum: {
            int count = menu.HowManyCells();
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = menu.getCell();
                cells.push_back(cell);
                it++;
            }

            float sum = arr.sum(cells.data(), count);
            Identifier cellToSave = menu.getCell();
            arr.changeValue(cellToSave, sum);
            arr.saveDataToFile();
            break;
        }
        case subtraction: {

        }
        case multiplication:{

        }
        case divide:{

        }
        case resize:{

        }
        case average:{

        }
        case save: {

        }
        case load: {

        }
        case changeValue: {

        }
        case noAction: {

        }
        case exitCode: {
            return 0;
        }
    }
}
