// Reverse Stack using Recursion (Array)
#include<stdio.h>
int stack[30],choice,size;
int head = -1;
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
        //printf("%d",head);
    }
}
int pop()
{
    int data,value;
    if(head<=-1)
    {
        printf("\nStack UnderFlow.");
    }
    else
    {
        //printf("\nThe popped element is %d.",stack[head]);
        value = stack[head];
        head--;
    }
    return value;
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
void bottom(int temp)
{
   int i;
   for(i=head;i>=0;i--)
   {
       stack[i+1] = stack[i];
   }
   head++;
   stack[0] = temp;
}
void reverse()
{
    int temp;
    if(head>=0)
    {
        temp = pop();
        reverse();
        bottom(temp);
    }
    else
        printf("Reverse Successful.");
}
void main()
{
    int forpop;

    printf("Enter size of stack:");
    scanf("%d",&size);
    do
    {
        printf("\n\n1. Push\n2. Pop\n3. Display\n4. Reverse\n5. Exit\nEnter Your Choice.");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push(stack,size);
                break;
            case 2:
                forpop = pop();
                break;
            case 3:
                display(stack);
                break;
            case 4:
                reverse();
                break;
            case 5:
                printf("Thank you!");
                break;
            default:
                printf("Enter a valid choice.");

        }
    }while(choice!=5);
}
