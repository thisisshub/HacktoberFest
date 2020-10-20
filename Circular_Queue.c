#include<stdio.h>
#define MAXSIZE 10
int front=-1, rear=-1,cqueue[MAXSIZE], item;
void enqueue();

void dequeue();
void display();

int main()
{
    int choice;
    char ch;
    do{
        printf("\n 1. ENQUEUE");
        printf("\n 2. DEQUEUE");
        printf("\n 3. DISPLAY");
        printf("\n 4. ENTER YOUR CHOICE:");
        scanf("%d", &choice);
        switch(choice){
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            default: printf("\n Wrong Choice.");
                break;
        }
        printf("Do you want to continue:");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }
    while(ch=='y');
    return 0;
}

void enqueue()
{
int item;
printf("Inset the element in queue : ");
scanf("%d", &item);
if (front==(rear+1)%MAXSIZE)
    printf("circular Queue Overflow \n");
else if (front == -1 && rear == -1 ) 	//If queue is initially empty
    {	front = rear = 0;
        cqueue[rear] = item; 
    }
else
{	
    rear = (rear + 1)%MAXSIZE;
    cqueue[rear] = item;
}
}
void dequeue()
{
    if (front == - 1)
    {
        printf("circular Queue Underflow \n");
    }
   else if(front==rear)
         {
        	front = rear = -1;
         }
    else
    {
        printf("Deleted Element is : %d\n", cqueue[front]);
        front = (front + 1)%MAXSIZE;
    }
}
        
    void display()
    {
    int i;
    if(front==-1 && rear==-1)
    {
        printf("The queue is Empty\n");
    }
    else
   {
        for(i= front; i!=rear;i=(i+1)%MAXSIZE)
          {
                printf("%d ",cqueue[i]);
          }
	 printf("%d ",cqueue[i]);
   }
}


