#include<graphics.h>
#include<iostream>
#include<cmath>
#include<ctime>
#define PI 3.1415
using namespace std;

int main()
{
	initwindow(500,500,"ANALOG CLOCK");
	{
		circle(250,250,200);
		circle(250,250,5);
		
		time_t now = time(0);
		tm *ltm = localtime(&now);
		system("cls");
		cout<<ltm->tm_hour<<" "<<ltm->tm_min;
	    
	    //hour hand
	    setcolor(WHITE);
	    line(250,250,250+150*sin(ltm->tm_hour * PI/6), 250-150*cos(ltm->tm_hour * PI/6));
	    
	    // minute hand
	    setcolor(WHITE);
	    line(250,250,250+190*sin(ltm->tm_min * PI/30), 250-190*cos(ltm->tm_hour * PI/30));
	}
	
	getch();
	closegraph();
	return 0;
}
