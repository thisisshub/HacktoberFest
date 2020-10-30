#include<ncurses.h>
#include <string>
#include "menu.h"

bool drawMap(WINDOW * win, int px, int py, int pe[5][2]){
	wmove(win, py, px);
	waddstr(win, "###");
	wmove(win, py+1, px+2);
	waddstr(win, "#####>");
	wmove(win, py+2, px);
	waddstr(win, "###");

	for(int i=0; i<5; i++){
		int ey= pe[i][1], ex= pe[i][0];
		bool flag=false;
		for(int a=px; a<7+px; a++)
			for(int b=py; b<py+3; b++)
				if(ey==b || ex==a) flag=true;
		if(flag) continue;
		wmove(win, ey, ex);
		waddstr(win, "X");
		if(ex==0) return true;
	}
	return false;
}

int main() {
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	WINDOW * win = newwin(48, 80, 0, 0);
	int player_x=5, player_y=24;
	int enemies[5][2]={{70,3},{70,5},{70,8},{70,15},{70,25}};
	char ch;
	while(1){
		bool check=drawMap(win, player_x, player_y, enemies);
		wrefresh(win);
		sleep(2);
		if(check) {
			break;
		}
		if((ch = getch()) != ERR){
			//playermove(ch);
		}
		for (int i=0; i<5; i++) enemies[i][0]--;
	}
	delwin(win);
	endwin();
	return 0;
}
