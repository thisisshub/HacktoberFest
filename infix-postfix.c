#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
        //printf("Pushed Successfully.");
    }
}
void pop(struct stack *s)
{
    int popped;
    if(isEmpty(*s))
        printf("\n The stack in empty-Underflow  Condition");
    else
    {
        popped =  s->data[s->top--];
       // printf("\n Popped Element: %d", popped);
    }
}
char peek(struct stack s)
{
    return (s.data[s.top]);
}
int priority(char a)
{
    switch(a)
    {
        case'+':
        case'-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return 0;
    }

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
    int n,i,j=0;
    initialize(&s);
    char infix[100],postfix[100];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        char a=infix[i];
        if(isOperator(a))
        {
            if(a=='('||isEmpty(s)||peek(s)=='(')
            {
                push(&s,a);
            }
            else if(a==')')
            {
                while(peek(s)!='(')
                {
                    char op=peek(s);
                    pop(&s);
                    postfix[j++]=op;
                }
                pop(&s);
            }
            else
            {
                if (priority(a)>priority(peek(s)))
                {
                    push(&s,a);
                }
                else
                {
                   while(!isEmpty(s)&&(priority(a)<priority(peek(s))))
                   {
                       char op=peek(s);
                       pop(&s);
                       postfix[j++]=op;
                   }
                   push(&s,a);
                }
            }
        }
        else
        {
            postfix[j++]=a;
        }
    }
    while(!isEmpty(s))
    {
        char op=peek(s);
        pop(&s);
        postfix[j++]=op;
    }
    postfix[j]='\0';
    printf("\n The postfix expression is:%s ",postfix);
}

