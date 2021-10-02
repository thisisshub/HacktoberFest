#include<stdio.h>
#include<stdlib.h>
# define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
if(front== -1 && rear== -1)
{ 
  front=rear=0;
  queue[rear]=x;
}
else if((rear+1)%N==front)
printf(" QUEUE IS FULL\n");

else
{
  rear=(rear+1)%N;
  queue[rear]=x;
}
 
}


void dequeue()
{
if(front == -1 && rear == -1)
printf("Queue Underflow\n");

else if(front == rear)
{ printf("DELETED ELEMENT IS %d\n",queue[front]);
front=rear= -1;}

else
{printf(" DELETED ELEMENT IS  %d\n",queue[front]);
front= (front+1)%N;}
}


void display()
{   int i=front;
    if(front== -1 && rear==-1)
    printf(" queue is empty\n");
    
    else
    {
        printf( " QUEUE IS:");
        while(i!=rear)
        {
            printf("->%d",queue[i]);
            i=(i+1)%N;
        }
        printf("->%d", queue[rear]);
    }
}



int main()
{
int ch,x;
while(1)
{
printf("\n1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Quit\n");
printf("Enter your choice : \n");
scanf("%d",&ch);
switch(ch)
{
case 1 :
printf("Input the element for insertion in queue : \n");
scanf("%d", &x);
enqueue(x);
display();
break;
case 2 :
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
}
}
}
