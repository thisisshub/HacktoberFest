#include <graphics.h>
#include <conio.h>
#include <dos.h>
main () {
  int x=0, i=0;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


for ( i = 0; i < 5; i++) {
    for (x=0; x<= 50; x++) {

      circle(230,100, 30);
      line(230,130, 230, 200);
      line(230,200, 210,250);
      line(230,200, 250,250);
      line(230,130, 210,170);
      line(230,130, 250,170);


      line(250,170, 400 + x,100 - x);
      rectangle(400 + x,100 - x, 450 + x,50 - x);
      delay(20);
      cleardevice();
    }

    for (x=0; x<= 50; x++) {

      circle(230,100, 30);
      line(230,130, 230, 200);
      line(230,200, 210,250);
      line(230,200, 250,250);
      line(230,130, 210,170);
      line(230,130, 250,170);


      line(250,170, 400 - x,100 + x);
      rectangle(400 - x,100 + x, 450 - x,50 + x);
      delay(20);
      cleardevice();
    }
  }


  getch();
  closegraph();
  return 0;
}
