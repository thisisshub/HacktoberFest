#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int value,front = -1,rear = -1,n = MAX ,choice,element;
int cqueue[MAX];

int isFull()
{
    if((rear+1)%n == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(rear == -1 && front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int value)
{
    if(isFull() == 1)
    {
        printf("The queue is full.");
        exit(0);
    }
    else
    {
        if(isEmpty() == 1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear+1)%n;
        }
    }
    cqueue[rear] = value;
}

void dequeue()
{
    if(isEmpty() == 1)
    {
        printf("Queue is empty.");
    }
    else
    {
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1)%n;
        }
    }
}

void display()
{
    if(isEmpty() == 1)
    {
        printf("Queue is empty.");
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d\t",cqueue[i]);
        }
    }
}

int peek()
{
    if(isEmpty() == 1)
    {
        printf("Queue is empty.");
    }
    else
    {
        return cqueue[front];
    }
}

int main()
{
    do
    {
       printf("\n1)Enqueue\n2)Dequeue\n3)Peek\n4)Display\n5)Exit");
       printf("\nSelect one operation : ");
       scanf("%d",&choice);
       switch(choice)
       {
        case 1 :
            printf("Enter a value :");
            scanf("%d",&value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            element = peek();
            printf("Front element is : ",element);
            break;
        case 4:
            display();
            break;
       }
    }while(choice != 5);
    return 0;
}
