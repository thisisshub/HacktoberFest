#include<graphics.h>  
#include<conio.h>  
void main()  
{  
    intgd=DETECT, gm, i, x, y;  
    initgraph(&gd, &gm, "C:\\TC\\BGI");  
    x=getmaxx()/3;  
    y=getmaxx()/3;  
    setbkcolor(WHITE);  
    setcolor(BLUE);  
    for(i=1;i<=8;i++)  
          {  
        setfillstyle(i,i);  
        delay(20);  
        circle(x, y, i*20);  
        floodfill(x-2+i*20,y,BLUE);  
    }  
    getch();  
    closegraph();  
}