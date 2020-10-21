// Implementing Stack Using Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void push()
{
    int value;
    struct node *prev,*newn;
    printf("\nEnter value to be pushed.");
    scanf("%d",&value);
    newn = malloc(sizeof(struct node));
    newn->data = value;
    if(head==NULL)
    {
        head = newn;
        newn->next = NULL;
    }
    else
    {
        prev = head;
        head = newn;
        newn->next = prev;

    }

}
void pop()
{
    struct node *prev,*temp;
    //temp = head;
    if(head==NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
       prev = head->next;
       temp = head;
       free(temp);
       head = prev;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        printf("\n%d\t",temp->data);
        temp = temp->next;
    }
}
void main()
{
    int choice;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nEnter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            //printf("In switch case");
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }while(choice!=4);
}
