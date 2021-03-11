#include "menu.h"
#include "ncurses.h"
int main() {

    initscr();
    move(10, 10);
    printw("Witaj świecie!");
    getch();
    refresh();
    return 0;
}
