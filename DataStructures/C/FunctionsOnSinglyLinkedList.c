/* A program that uses functions to perform the following:
    a. Create a Singly Linked list of integers
    b. Delete a Given number
    c. Display the content after Deletion
    d. Reverse of Linked list
    All operations that can be performed on a singly linked list.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *temp ,*prev,*newn;

void begin()
{
    newn->next = head;
    head = newn;
    //printf("\nInsertion Successful");
}
void after(int value)
{
    temp = head;
    while(temp->data!=value)
    {
        temp=temp->next;
    }
    if(temp->data==value)
    {
        newn->next = temp->next;
        temp->next = newn;
        //printf("\nInsertion Successful");
    }
}
void before(int value)
{
    temp = head;
    while(temp->data!=value)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp->data==value)
    {
        newn->next = prev->next;
        prev->next = newn;
        //printf("\nInsertion Successful");
    }
}
void endin()
{
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newn;
    newn->next = NULL;
    //printf("\nInsertion Successful");
}

void create()
{
    newn = malloc(sizeof(struct node));
    printf("\nEnter value to be inserted.\n");
    scanf("%d",&newn->data);
    if(head == NULL)
    {
        head = newn;
        newn->next=NULL;
        //printf("\nInsertion Successful");
    }
    else
    {   int insert,value1,value2;
        printf("\nWhere do you want the value to be inserted?\n");
        printf("\n1. At beginning\n2. After an element\n3. Before an element\n4. At end.\n");
        scanf("%d",&insert);
        switch(insert)
        {
            case 1:
                begin();
                break;
            case 2:
                printf("\nAfter which value do you want to insert %d?",newn->data);
                scanf("%d",&value1);
                after(value1);
                break;
            case 3:
                printf("\nBefore which value do you want to insert %d?",newn->data);
                scanf("%d",&value2);
                before(value2);
                break;
            case 4:
                endin();
                break;
        }
    }
}
void deletev()
{
    int del;
    printf("\nEnter value to be deleted.");
    scanf("%d",&del);
    temp=head;
    if(temp->data==del)
    {
        head = temp->next;
        free(temp);
        //printf("Deletion Successful");
    }
    else
    {
        while(temp->data!=del)
        {
            prev = temp;
            temp=temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

}
void display()
{
    temp = head;
    if(temp==NULL)
    {
        printf("\nList is Empty.");
    }
    else
    {
        printf("\n**********************************************\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n**********************************************\n");
    }
}
void reverse()
{
    int i=0;
    struct node *nextn;
    temp=head;
    prev = NULL;
    while(temp!=NULL)
    {
        nextn = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextn;
    }
    //head->next = NULL;
    head = prev;

}
void main()
{
    int choice;
    do
    {
        printf("\n1. Enter value\n2. Delete Value\n3. Display List\n4. Reverse\n5. Exit\nEnter Your Choice.");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                deletev();
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                break;
            case 5:
                printf("Thank You!");
        }
    }while(choice!=5);
}
