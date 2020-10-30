// To find the largest element in Doubly Linked List.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *temp,*newn;
void insert()
{
    newn = malloc(sizeof(struct node));
    printf("\nEnter value to be inserted.");
    scanf("%d",&newn->data);
    newn->next = NULL;
    if(head == NULL)
    {
        head = newn;
        newn->prev = NULL;
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
}
int largest()
{
    int large;
    temp = head;
    large = head->data;
    while(temp!=NULL)
    {
        if(temp->data>large)
        {
            large = temp->data;
        }
        temp = temp->next;
    }
    return large;
}
void main()
{
    int choice,largest_value;
    do
    {
        printf("\n1. Insert\n2. Find Largest Element\n3. Exit\nEnter your choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                largest_value = largest();
                printf("\nLargest Value Stored in the list is %d.\n\n",largest_value);
                break;
            case 3:
                printf("\nThank You!");
                break;
        }
    }while(choice!=3);
}
