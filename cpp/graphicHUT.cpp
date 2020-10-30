int gd = DETECT , gm,a,b,i,r,x,y;
	initgraph(&gd,&gm,"");
	
	//triangle
	setfillstyle(SOLID_FILL,YELLOW);
	line(150,100,65,225);
	line(150,100,225,225);
	line(65,225,225,225);
	floodfill(150,160,WHITE);
	
	//upper rect
	setfillstyle(SOLID_FILL,YELLOW);
	line(150,100,330,75);
	line(225,225,430,195);
	line(150,100,225,225);
	line(330,75,430,195);
	floodfill(300,150,WHITE);
	
	//LOWER LEFT RECT
	setfillstyle(SOLID_FILL,BROWN);
	rectangle(65,225,225,390);
	floodfill(130,275,WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(125,300,170,390);
	rectangle(75,300,110,335);
	floodfill(150,350,WHITE);
	floodfill(95,320,WHITE);	
	line(145,300,145,390);
	line(90,300,90,335);
	
	//lower right rect
	setfillstyle(SOLID_FILL,BROWN);
	line(225,225,430,195);
    line(225,225,225,390);
    line(225,390,430,340);
    line(430,340,430,195);
	floodfill(300,300,WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(325,280,370,360);
	rectangle(260,295,300,325);
	floodfill(270,310,WHITE);
	floodfill(350,310,WHITE);
    line(345,285,345,360);
	line(280,300,280,330);
	
	//circle
	setfillstyle(SOLID_FILL,YELLOW);
	circle(330,235,15);
	floodfill(330,235,WHITE);
	
	//lines
	a=150;
	b=100;
	r=120;
	for(i=0;i<=360;i=i+20)
	{
		x=r*cos(i*3.14/300);
		y=r*sin(i*3.14/300);
		line(a,b,a+x,b-y);
	}
	
	getch();
	closegraph();
}
