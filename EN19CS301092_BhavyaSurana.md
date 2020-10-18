#include<stdio.h>
#include<stdlib.h>

#define size 3

int stack[size];
int top=-1;

void push()
{  int x;
   printf("Enter data\n");
   scanf("%d",&x);
   if(top==size-1)
   {printf("Overflow condition\n");}
   else
   {top++;
   stack[top]=x;
   }
}
void pop()
{ int y;
  if(top==-1)
  {printf("Stack underflow\n");
  }
  else
  {y=stack[top];
   top--;
   printf("%d",y);
  }
  printf("successfully popped\n");
}
void display()
{int i;
 for(i=top;i>=0;i--)
 {printf("%d",stack[i]);
 }
}

int main()
{ int ch;
  do
  { printf("Enter choice:1 for push; 2:pop; 3:display ");
    scanf("%d",&ch);
    switch(ch)
    { case 1: push();
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      default: printf("Invalid choice");
    }
  }
  while(ch!=0);
  return 0;
}
              
