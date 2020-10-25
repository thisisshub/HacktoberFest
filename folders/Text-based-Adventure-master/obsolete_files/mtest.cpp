#include "mainMenu.h"

int main() {
	initscr();
	cbreak();

	int y, x;
	getmaxyx(stdscr, y, x);
	WINDOW * mm = newwin(y, x, 0, 0);
	wrefresh(mm);
	main_menu(mm, y, x);
	delwin(mm);
	endwin();

}
