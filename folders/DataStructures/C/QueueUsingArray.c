// To implement Queue Using Array.
#include<stdio.h>
int queue[20],size,front,rear;
front = -1;
rear = -1;
void enqueue()
{
    int value;
    if(rear == size-1)
    {
        printf("Queue Overflow.");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("Enter value to be inserted.");
        scanf("%d",&value);
        rear++;
        queue[rear]=value;
    }
}
void dequeue()
{
    if(front == -1 || front>rear)
    {
        printf("***********\n");
        printf("Queue Underflow.");
        printf("\n***********");
    }
    else
    {
        printf("%d is deleted.",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1 || front>rear)
    {
        printf("***********\n");
        printf("Queue is empty.");
        printf("\n***********");
    }
    else
    {
        printf("***********\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n***********");
    }
}
void main()
{
    int choice;
    printf("Enter the size of array.");
    scanf("%d",&size);
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter Your Choice.\n");
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
                printf("Thank you!");
                break;
            default:
                printf("Enter a valid choice.");
        }
    }while(choice!=4);

}
