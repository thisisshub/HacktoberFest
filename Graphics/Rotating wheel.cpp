#include<math.h>
#include<graphics.h>
#define N getmaxy()
#define Radius 40
 void main()
 {
   //graphics variables
   int gd=DETECT,gm;

   //xc,yc coordinate of center
   //i for loop iteration
   int i,xc,yc;

   //rx1,ry1,sep used for wheel's cross
   int rx1,ry1,sep;

   //change bgi directory according to your's
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");

   //initialise yc it is constant
   yc=getmaxy()/2-Radius;
   i=0;

   //loop stops when keyboard key down or i>=N
   //kbhit checks whether keyboard pressed or not
   while(i<N&&!kbhit())
   {

   //increment xc for moving the wheel
   xc=i;
   delay(50);

   //clear previous screen
   clearviewport();

   //represent road or some ground as stright line
   line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

   //draw wheel
   circle(xc,yc,Radius);

   //following if else block draws
   //wheel cross in two arrangments shows alternatively
   if(i%2==0)
   {
     line(xc,yc+Radius,xc,yc-Radius);
     line(xc-Radius,yc,xc+Radius,yc);
   }
   else
   {
     rx1=xc-(Radius/sqrt(2));
     ry1=yc-(Radius/sqrt(2));
     sep=sqrt(2)*Radius;
     line(rx1,ry1,rx1+sep,ry1+sep);
     line(rx1,ry1+sep,rx1+sep,ry1);
   }

   //increment i
   i+=3;
  }
} 
