// Implement Circular Queue using Array.
#include<stdio.h>
int f=-1;
int r=-1;
int queue[20],size;
void enqueue()
{
    int value;
    if(f==0 && r==size-1 || f==r+1)
    {
        printf("Queue Overflow.");
    }
    else
    {
        printf("Enter value to be inserted.");
        scanf("%d",&value);
        if(f==-1)
        {
            f=0;
            r=0;
        }
        else
        {
            if(r==size-1)
            {
                r=0;
            }
            else
            {
                r++;
            }
        }
        queue[r]=value;
        printf("\nValue inserted at queue[%d]",r);
    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("\nQueue Underflow.");
    }
    else
    {
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            printf("\nElement deleted is %d.",queue[f]);
             printf("\nElement deleted from queue[%d]",f);
            if(f==size-1)
            {
                f=0;
            }
            else
            {
                f++;
            }
        }
    }
}
void display()
{
    int front = f;
    int rear = r;
    if(front==-1)
    {
        printf("Queue is empty.");
    }
    printf("\nQueue elements:\n");
    if(front<=rear)
    {
        while(front<=rear)
        {
            printf("%d\t",queue[front]);
            front++;
        }
    }
    else
    {
        while(front<=size-1)
        {
            printf("%d\t",queue[front]);
            front++;
        }
        front = 0;
        while(front<=rear)
        {
            printf("%d\t",queue[front]);
            front++;
        }
    }
    printf("\n");
}
void main()
{
    printf("\nEnter size of queue:");
    scanf("%d",&size);
    int choice;
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
        }
    }while(choice!=4);
}
