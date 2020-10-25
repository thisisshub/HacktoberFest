#include<ncurses.h>
#include<unistd.h>
int main(){
	initscr();
	noecho();
	WINDOW * win = newwin(25, 25, 0, 0);
	wrefresh(win);
	//waddch(win, 'w');
	//printw("Please output this correctly\n");
	waddstr(win, "Printt this\n");
	waddch(win, '1');
	wrefresh(win);
	sleep(5);
	delwin(win);
	endwin();
	return 0;
}
