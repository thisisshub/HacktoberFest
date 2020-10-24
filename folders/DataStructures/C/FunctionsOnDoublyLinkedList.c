/* A program that uses functions to perform the following:
    a. Create a Doubly Linked list of integers
    b. Delete a Given number
    c. Display the content after Deletion
    d. Reverse of Linked list
    All operations that can be performed on a doubly linked list.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *temp ,*prevn,*newn;

void begin()
{
    head->prev = newn;
    newn->next = head;
    head = newn;
    newn->prev = NULL;
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
        newn->prev = temp;
        temp->next = newn;
        newn->next->prev = newn;
        //printf("\nInsertion Successful");
    }
}
void before(int value)
{
    temp = head;
    while(temp->data!=value)
    {
        prevn = temp;
        temp = temp->next;
    }
    if(temp->data==value)
    {
        temp->prev->next = newn;
        newn->prev = temp->prev;
        newn->next = temp;
        temp->prev = newn;

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
    newn->prev = temp;
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
        newn->prev=NULL;
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
    temp = head;
    if(temp==NULL)
    {
        printf("No element found.");
    }
    else
    {
        printf("Enter value to be deleted.");
        scanf("%d",&del);
        while(temp->data!=del)
        {
            temp = temp->next;
        }
        if(temp->prev==NULL && temp->next==NULL)
        {
            free(temp);
            head = NULL;
        }
        else
        {
                if(temp->prev==NULL)
                {
                    head = temp->next;
                    head->prev = NULL;
                    free(temp);
                }
                else
                {
                    if(temp->next==NULL)
                    {
                        temp->prev->next = NULL;
                        free(temp);
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        free(temp);
                    }
                }
        }
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
void main()
{
    int choice;
    do
    {
        printf("\n1. Enter value\n2. Delete Value\n3. Display List\n4. Exit\nEnter Your Choice.");
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
                printf("Thank You!");
        }
    }while(choice!=4);
}
