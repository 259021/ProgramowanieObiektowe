//
// Created by osboxes on 5/11/21.
//

#include "operation_handler.h"


int OperationHandler::decimalOperation(Operations operation, Array *arr) {
    switch (operation) {
        case sum: {
            int count = (int)Menu::getNumber("How many cells you want to use?");
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = Menu::getIdentifier("Which cell dou you want to select to sum operation? ");
                cells.push_back(cell);
                it++;
            }

            float sum = arr->sum(cells.data(), count);
            Identifier destination = Menu::getIdentifier("Where do you want to save result?");
            DecimalCell cell = DecimalCell(std::to_string(sum));
            arr->changeValue(destination, cell);
            arr->saveDataToFile();
            break;
        }
        case subtraction: {
            Identifier minued = Menu::getIdentifier("select minued cell: ");
            Identifier subtrahend = Menu::getIdentifier("Select subtrahend cell: ");
            float value = arr->subtract(minued, subtrahend);
            Identifier destination = Menu::getIdentifier("Where do you want to save result?");
            DecimalCell cell = DecimalCell(std::to_string(sum));
            arr->changeValue(destination, cell);
            arr->saveDataToFile();
            break;
        }
        case multiplication:{
            int count = (int)Menu::getNumber("How many cells you want to use?");
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = Menu::getIdentifier("Which cell dou you want to select to multiplication operation?");
                cells.push_back(cell);
                it++;
            }

            float sum = arr->multiplication(cells.data(), count);
            Identifier destination = Menu::getIdentifier("Where do you want to save result?\n");
            DecimalCell cell = DecimalCell(std::to_string(sum));
            arr->changeValue(destination, cell);
            arr->saveDataToFile();
            break;
        }
        case divide:{
            Identifier divisor = Menu::getIdentifier("select divide cell: ");
            Identifier dividend = Menu::getIdentifier("Select dividend cell: ");
            float value = arr->divide(divisor, dividend);
            Identifier destination = Menu::getIdentifier("Where do you want to save result?");
            DecimalCell cell = DecimalCell(std::to_string(value));
            arr->changeValue(destination, cell);
            arr->saveDataToFile();
            break;
        }
        case resize:{
            Identifier size = Menu::getIdentifier("Pass size of your new sheet. ");
            arr->resizeSheet(size.Column + 1, size.Row + 1);
            break;
        }
        case average:{
            int count = (int)Menu::getNumber("How many cells you want to use?");
            std::vector<Identifier> cells;
            auto it = cells.begin();
            for (int i = 0; i < count; ++i) {
                Identifier cell = Menu::getIdentifier("Which cell dou you want to select to average operation? ");
                cells.push_back(cell);
                it++;
            }

            float sum = arr->average(cells.data(), count);
            Identifier destination = Menu::getIdentifier("Where do you want to save result?");
            DecimalCell cell = DecimalCell(std::to_string(sum));
            arr->changeValue(destination, cell);
            arr->saveDataToFile();
            break;
        }
        case save: {
            arr->saveDataToFile();
            Menu::alert("Data saved to file.");
            break;
        }
        case load: {
            arr->loadDataFromFile();
            Menu::alert("Data loaded from file.");
            break;
        }
        case changeValue: {
            Identifier destination = Menu::getIdentifier("Which cell value you want to change?");
            Cell value = Menu::getCell("Pass new value.");
            arr->changeValue(destination, value);
            break;
        }
        case noAction: {
            //Menu::alert("No proper action selected!");
            break;
        }
        case exitCode: {
            return -1;
            break;
        }
    }
    return 0;
}
