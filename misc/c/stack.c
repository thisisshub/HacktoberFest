/*Implementation of stack using array(without structure)*/

#include<stdio.h>
#define MAX 5
int arr[MAX],top=-1;

void push()
{

    if(top==MAX-1)
    {
        printf("the stack is full:Overflow");
        return;
    }
    else{
        printf("Enter the element: ");
        scanf("%d",&arr[++top]);
    }
}
void pop()
{
    int popped;
    if(top==-1)
    {
        printf("Stack is empty:Underflow");
    }
    else
    {
       popped= arr[top--];
       printf("%d is popped",popped);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("No elements in the stack:Underflow");
    }
    else
    {
        printf("The elements are:");
        for(i=top;i>=0;i--)
            printf("\n %d",arr[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("Select the option to perform operation :\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
        printf("\n Choose: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
             case 2:
                pop();
                break;
             case 3:
                display();
                break;
             case 4:
                exit(0);
                break;
             default :
                printf("Invalid choice");
        }
    }
}
