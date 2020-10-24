/*Implementation of Queue using arrays */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 5

struct Queue
{
    int data[MAX];
    int front,rear;
};

void initialize(struct Queue *q)
{
    q->front=q->rear= -1;
}

int isFull(struct Queue *q)
{
    return (q->rear==MAX-1)?1:0;
}

int isEmpty(struct Queue *q)
{
    return (q->rear==-1)?1:0;
}

int insert(struct Queue *q,int d)
{
    if(isFull(q))
        return 0;

    q->data[++q->rear]=d;

    if(q->front==-1)
        q->front=0;

    return 1;
}


void display(struct Queue *q)
{
    int i;

    if(isEmpty(q))
        printf("\n\tQueue is Empty->");
    else
    {
        printf("\nQueue Contents ->->\n");
        printf("Queue Size : %d\nFront = %d\nRear = %d\n",MAX,q->front,q->rear);

    for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\n",q->data[i]);
        }
    }
}


int delete(struct Queue *q)
{
    int d;

    d=q->data[q->front];

    if(q->front==q->rear)
        q->front=q->rear=-1;
    else
        q->front++;

    return d;
}

int search(struct Queue *q,int k)
{
    int i;

    for(i=q->front;i<=q->rear;i++)
        if(q->data[i]==k)
            return i;

    return -1;
}


int main()
{
int ch,d;
struct Queue q;
initialize(&q);
while(1)
{
    printf("\n\t\t\t MENU\n 1. Insert.\n 2. Delete.\n 3. Search.");
    printf("\n 4. Display.\n 5. Exit.");
    printf("\n\t Enter your choice :: ");
    scanf("%d",&ch);
switch(ch)
{
case 1:
    printf("\n  Enter Data to be Inserted : ");
    scanf("%d",&d);
    d=insert(&q,d);
    if(d==0)
        printf("    Queue is full...");
    else
        printf("    Insertion done successfully...");
    break;
case 2:
    if(isEmpty(&q))
        printf("\n  Queue is empty...");
    else
        printf("\n  Deleted element is %d",delete(&q));
    break;
case 3:
    printf("\n  Enter Data to be Searched : ");
    scanf("%d",&d);
    d=search(&q,d);
    if(d==-1)
        printf("\n  Key is not found..");
    else
        printf("\n  Key is found at location %d..",d);
    break;
case 4:
    display(&q);
    break;
case 5:
    exit(0);
default:
    printf("\n\t    Please enter correct choice->->->->");
}
}
}

