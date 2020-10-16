#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
main()
{
int x,y,l,i=0,k=0,c=0,p=25,q=75,j=100;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

for(i=0;i<=500;i++)
{
	//rain
	x = getmaxx(); //get maximum (x) pixel value
	y = getmaxy(); //get maximun (y) pixel value
	for(l=0;l<100;l++)
	{
	// display '.' at any (x,y) combination
	outtextxy(random(x),random(y),".");
	}

	//upperbody
	circle(50+i,315,20);
	line(50+i,335,50+i,400);
	line(50+i,355,80+i,335);
	line(80+i,335,80+i,275);
	line(20+i,275,140+i,275);
	arc(80+i,275,0,180,60);

	//movinghand

	if(c==0)
	{
		line(50+i,355,i+p,380);
		p=p+5;

		if(p>75)
		{
			c=1;
			p=25;
		}
	}

	if(c==1)
	{
		line(50+i,355,i+q,380);
		q=q-5;

		if(q<25)
		{
			c=0;
			q=75;
		}
	}

	//legs
	line(50+i,400,i+k,450);
	k=k+10;

	if(k>100)
	{
		k=0;
	}

	line(50+i,400,i+j,450);
	j = j-10;

	if (j<0)
	{
		j=100;
	}

	delay(30);
	cleardevice();
}

getch();
closegraph();
return 0;
}
