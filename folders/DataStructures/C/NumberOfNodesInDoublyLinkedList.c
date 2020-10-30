// Count number of nodes in Doubly Linked List.
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

void insert()
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
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = NULL;
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
void count_nodes()
{
    int count=0;
    temp =head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("%d",count);
}
void main()
{
    int choice;
    do
    {
        printf("\n1. Enter value\n2. Delete Value\n3. Display List\n4. Number of nodes.\n5. Exit\nEnter Your Choice.");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                deletev();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nNumber of Nodes\n");
                count_nodes();
                break;
            case 5:
                printf("Thank You!");
        }
    }while(choice!=5);
}
