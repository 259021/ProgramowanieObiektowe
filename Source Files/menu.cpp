#include "menu.h"
#include "ncurses.h"

#include "array.h"


  void Menu::Show() {

    Array arr = Array(4, 2);

      initscr();
      // creating a window;
      // with height = 15 and width = 10
      // also with start x axis 10 and start y axis = 20
      WINDOW *win = newwin(15, 17, 2, 10);
      refresh();

      // making box border with default border styles


      // move and print in window
      mvwprintw(win, 0, 1, "Greeter");
      mvwprintw(win, 1, 1, "Hello");

      // refreshing the window
      wrefresh(win);

      getch();
      endwin();

}

