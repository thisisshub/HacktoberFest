// Compare If two linked lists are identical or not.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int result=1;
struct node *head = NULL;
struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *insert()
{
    struct node *temp,*newn,*prev;
    newn = malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newn->data);
    temp = head;
    if(temp==NULL)
    {
        head = newn;
        newn->next = NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->next = NULL;
    }
    return head;
}
int compare(struct node *h1, struct node *h2)
{
    struct node *temp1,*temp2;
    temp1 = h1;
    temp2 = h2;
    while(temp1->next!=NULL && temp2->next!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            result = 0;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if((temp1==NULL && temp2!=NULL)||(temp1!=NULL && temp2==NULL))
    {
        result = 0;
    }

}
void main()
{
    int choice1,choice2, result;
    printf("Construct First Linked List.");
    do
    {
        head1 = insert();
        printf("Do you want to insert any element?(1/0)");
        scanf("%d",&choice1);
    }while(choice1!=0);
      printf("Construct Second Linked List.");
    do
    {
        head2 = insert();
        printf("Do you want to insert any element?(1/0)");
        scanf("%d",&choice2);
    }while(choice2!=0);
    result = compare(head1,head2);
    if(result==1)
    {
        printf("Lists are identical");
    }
    else
    {
        printf("Lists are Different.");
    }
}
