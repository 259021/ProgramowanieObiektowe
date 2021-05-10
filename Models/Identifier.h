//
// Created by osboxes on 3/11/21.
//

#ifndef OWNEXCEL_IDENTIFIER_H
#define OWNEXCEL_IDENTIFIER_H


class Identifier {
    /*
     * /brief This model helps identifier position of single value in sheet.
     *
     */
public:
    int Column;
    int Row;
    Identifier(int column, int row){
        Column = column - 1;
        Row = row - 1;
    }
    Identifier() {
        Column = 0;
        Row = 0;
    }
};


#endif //OWNEXCEL_IDENTIFIER_H
