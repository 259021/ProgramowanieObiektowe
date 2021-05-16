#include "menu.h"
#include "array_display.h"
#include "operation_handler.h"


int main() {
    //MARK: - Create instances of classes -
    Array arr = Array(5,5);
    ArrayDisplay sheet = ArrayDisplay();
    int exit = 0;

    //MARK: - Prepare sheet -
    try {
        arr.loadDataFromFile();
    }
    catch (...) {
        Identifier size = Menu::getIdentifier("Pass size of your sheet.");
        arr = Array(size.Column, size.Row);
        arr.saveDataToFile();
    }

    //MARK: - Main loop -
    while(exit != -1) {
        Menu::clear();
        sheet.Display(arr);
        Operations operation = Menu::showFunctions();
        try {
            exit = OperationHandler::decimalOperation(operation, &arr);
        }
        catch(const std::exception& exception) {
            Menu::alert(exception.what());
        }
        catch(const std::runtime_error& exception) {
            Menu::alert(exception.what());
        }
        catch(const std::out_of_range& exception) {
            Menu::alert(exception.what());
        }
    }
}





















/*
 //MARK: - handling actions -
    switch (operation) {
        case sum: {
            int count = (int)menu.getNumber("How many cells you want to use?");
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = menu.getIdentifier("Which cell dou you want to select to sum operation? ");
                cells.push_back(cell);
                it++;
            }

            float sum = arr.sum(cells.data(), count);
            Identifier destination = menu.getIdentifier("Where do you want to save result?");
            arr.changeValue(destination, sum);
            arr.saveDataToFile();
            break;
        }
        case subtraction: {
            Identifier minued = menu.getIdentifier("select minued cell.");
            Identifier subtrahend = menu.getIdentifier("Select subtrahend cell");
            float value = arr.subtract(minued, subtrahend);
            Identifier destination = menu.getIdentifier("Where do you want to save result?");
            arr.changeValue(destination, value);
            arr.saveDataToFile();
            break;
        }
        case multiplication:{
            int count = (int)menu.getNumber("How many cells you want to use?");
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = menu.getIdentifier("Which cell dou you want to select to multiplication operation? ");
                cells.push_back(cell);
                it++;
            }

            float sum = arr.multiplication(cells.data(), count);
            Identifier destination = menu.getIdentifier("Where do you want to save result?");
            arr.changeValue(destination, sum);
            arr.saveDataToFile();
            break;
        }
        case divide:{
            Identifier divisor = menu.getIdentifier("select minued cell.");
            Identifier dividend = menu.getIdentifier("Select subtrahend cell");
            float value = arr.divide(divisor, dividend);
            Identifier destination = menu.getIdentifier("Where do you want to save result?");
            arr.changeValue(destination, value);
            arr.saveDataToFile();
            break;
        }
        case resize:{
            Identifier size = menu.getIdentifier("Pass size of your new sheet. ");
            arr.resizeSheet(size.Column, size.Row);
            break;
        }
        case average:{
            int count = (int)menu.getNumber("How many cells you want to use?");
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = menu.getIdentifier("Which cell dou you want to select to average operation? ");
                cells.push_back(cell);
                it++;
            }

            float sum = arr.average(cells.data(), count);
            Identifier destination = menu.getIdentifier("Where do you want to save result?");
            arr.changeValue(destination, sum);
            arr.saveDataToFile();
            break;
        }
        case save: {
            arr.saveDataToFile();
        }
        case load: {
            arr.loadDataFromFile();
        }
        case changeValue: {
            Identifier destination = menu.getIdentifier("Which cell value you want to change?");
            float value = menu.getNumber("Pass new value.");
            arr.changeValue(destination, value);
        }
        case noAction: {
        menu.message("No proper action selected!");
        }
        case exitCode: {
            return 0;
        }
    }
 */