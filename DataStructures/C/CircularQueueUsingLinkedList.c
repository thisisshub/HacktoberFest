// Implement Circular queue using linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front,*rear,*temp,*newn;
void enqueue()
{
    newn = malloc(sizeof(struct node));
    printf("\nEnter value to be inserted.");
    scanf("%d",&newn->data);
    if(front==NULL)
    {
        front = newn;
        rear = newn;
    }
    else
    {
        rear->next = newn;
        rear = newn;
    }
    rear ->next = front;
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Queue Underflow.");
    }
    else
    {
        temp = front;
        front = temp->next;
        rear->next = temp->next;
        free(temp);
    }
}
void display()
{
    temp = front;
    do
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=front);

}
void main()
{
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
