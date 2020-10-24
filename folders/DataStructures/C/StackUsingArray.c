// Implement Stack Using Array.
#include<stdio.h>
int stack[30],head,choice,size;
head = -1;
void push(int stack[30],int size)
{
    int data;
    if(head>=size-1)
    {
        printf("\nStack OverFlow.");
    }
    else
    {
        printf("\nEnter data:");
        scanf("%d",&data);
        head++;
        stack[head] = data;
        printf("%d",head);
    }
}
void pop(int stack[], int size)
{
    int data;
    if(head<=-1)
    {
        printf("\nStack UnderFlow.");
    }
    else
    {
        printf("\nThe popped element is %d.",stack[head]);
        head--;
    }
}
void display(int stack[30])
{
    int i;
    if(head>=0)
    {
        for(i=head;i>=0;i--)
        {
            printf("\n%d",stack[i]);
        }
    }
    else
    {
        printf("Stack is Empty.");
    }
}

void main()
{

    printf("Enter size of stack:");
    scanf("%d",&size);
    do
    {
        printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter Your Choice.");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push(stack,size);
                break;
            case 2:
                pop(stack,size);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Thank you!");
                break;
            default:
                printf("Enter a valid choice.");

        }
    }while(choice!=4);
}
