// To implement Queue using Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *newn,*temp;
void enqueue()
{
    newn = malloc(sizeof(struct node));
    printf("Enter value to be inserted.");
    scanf("%d",&newn->data);
    newn->next = NULL;
    if(front==NULL)
    {
        front = newn;
    }
    else
    {
        rear->next = newn;
    }
    rear = newn;
}
void dequeue()
{
    if(front == NULL || rear == NULL)
    {
        printf("Queue Underflow.");
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}
void display()
{
    if(front == NULL)
    {
        printf("Queue is Empty.");
    }
    else
    {
        temp = front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int choice;
    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter Your Choice.");
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
                printf("Thank You!");
                break;
            default:
                printf("Enter valid choice.");
        }
    }while(choice!=4);
}
