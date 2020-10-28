//implementing bothoprn in a circular queue
#include<stdio.h>
#include<conio.h>
#define max 4
int a[max],front=-1,rear=-1;
void insert();
void delet();
void display();
void main()
{
 int sel,flag;
 clrscr();
 do
 {
   printf("Please select from the following options"
	  "\n1:Insert"
	  "\n2:Delete"
	  "\n3:Display");
   scanf("%d",&sel);
   switch(sel)
   {
     case 1:
     insert();
     break;
     case 2:
     delet();
     break;
     case 3:
     display();
     break;
   }
 printf("Press 1 to continue ");
 scanf("%d",&flag);
}
while(flag==1);
getch();
}
void insert()
{
 int num;
 printf("Please enter the number you want to insert ");
 scanf("%d",&num);
 if(front==0 && rear==-1)
 {
   printf("Overflow");
 }
 else if(front==-1 && rear==-1)
 {
   front=rear=0;
   a[rear]=num;
 }
 else if(rear==max-1 && front!=0)
 {
   rear=0;
   a[rear]=num;
 }
 else
 {
  rear=rear+1;
  a[rear]=num;
 }
}
void delet()
{
 int temp;
 if(front==-1)
 {
  printf("Underflow");
 }
 if(front==rear)
 {
  front=rear=-1;
 }
 else if(front==max-1)
 {
  front=0;
 }
 else
 {
 front=front+1;
 }
}
void display()
{
 int i;
 if(front<rear)
 {
  for(i=front;i<rear;i++)
   {
     printf("%d\n",a[i]);
   }
  }
  else
  {
   if(front>rear)
   {
    for(i=front;i<=max-1;i++)
     printf("%d\n",a[i]);
  }
  }
}
