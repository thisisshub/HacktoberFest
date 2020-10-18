#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
struct stack {
    char data[MAX];
    int top;
};

void initialize(struct stack *s){
    s->top=-1;
}
int isEmpty(struct stack s)
{
   if(s.top == -1)
 	 return 1;
   else
	 return 0;
}

int isFull(struct stack s)
{
   if (s.top == MAX - 1)
	 return 1;
   else
	 return 0;
}
void push(struct stack *s, char data)
{
    if(isFull(*s))
        printf("\nThe stack is full- Overflow Condition");
    else
    {
        s->data[++s->top] = data;
    }
}
int pop(struct stack *s)
{
    int popped;
    if(isEmpty(*s))
        printf("\n The stack in empty-Underflow  Condition");
    else
    {
        popped =  s->data[s->top--];
    }
    return popped;
}

int isOperator(char a)
{
    if(a=='+'|| a=='-'|| a=='*'|| a=='/'|| a=='%'|| a=='^'|| a=='$'|| a=='('|| a==')')
    {
        return 1;
    }
    else
        return 0;
}

void main()
{
    struct stack s;
    int n,i,j=0,value,result;
    initialize(&s);
    char postfix[100];
    printf("Enter the postfix expression:");
    scanf("%s",&postfix);
     for(i=0;postfix[i]!='\0';i++)
    {
        char a=postfix[i];
        if(isOperator(a)==0)
        {
            int oper=postfix[i]-'0';
            push(&s,oper);
            }
        else
            {
              int op2 =pop(&s);
              int op1 =pop(&s);
              switch(a)
              {
              case '+':
                value=op1+op2;
                break;
             case '-':
                value=op1-op2;
                break;
             case '*':
                value=op1*op2;
                break;
             case '/':
                value=op1/op2;
                break;
             case '%':
                value=op1%op2;
                break;
             case '^':
                value=pow(op1,op2);
                 break;
              }
              push(&s,value);
            }
    }
    printf("\n The evaluation of the postfix expression is: %d ",pop(&s));
}
