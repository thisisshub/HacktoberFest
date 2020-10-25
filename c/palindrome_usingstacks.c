#include<stdio.h>
#include<stdlib.h>
# define max 4
int a[max],top;
top=-1;
void push(int val)
{
    if(top==max-1)
        printf("\n Stack Overflow !! No values can be added now.\n");
    else
    {
        top++;
        a[top]=val;
    }
}
void pop()
{
    if(top==-1)
        printf("\n Stack underflow !! No elements can be deleted.\n");
    else
    {
        printf("The element to be deleted is %d.",a[top]);
        top--;
    }
}
void display()
{
    int pos;
    pos=0;
    printf("\n ELEMENTS OF STACK : ");
        while(pos<=top)
    {
        printf("\t%d",a[top-pos]);
        pos++;
    }
}
void pal()
{
    int flag,i;
    for(i=0;i<=(top+1)/2;++i)
    {
        if(a[top-i]==a[i])
        {

            flag=0;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\n\t STACK IS PALINDROME.");
    else
        printf("\n\t STACK IS NOT PALINDROME.");
}
void status()
{
    printf("\n The status of top is %d\n",top);
}
int main()
{
    int ch,val;
while(ch!=5)
{
printf("\n\n\t MENU \n 1. PUSH VALUES IN STACK\n 2.POP VALUE FROM STACK\n 3.STACK IS PALINDROME OR NOT\n 4.STATUS OF STACK\n 5.EXIT \n\n Enter your choice : ");
scanf("%d",&ch);
switch(ch)
{
    case 1 : printf("\n Enter value to be pushed in stack : ");
             scanf("%d",&val);
             push(val);
             break;
    case 2 : pop();
             break;
    case 3 : pal();
             break;
    case 4 : display();
             status();
             break;
    case 5 : exit(0);
             break;
   default : printf("Invalid Choice !!!!!\n");
}
}
 return 0;

}
