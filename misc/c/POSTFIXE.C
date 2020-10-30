#include<stdio.h>
#include<conio.h>
#define SIZE 50
int top = -1 ;
int stack[SIZE] ;
void push(int value)
{
	if(top == SIZE-1)
	{
		printf("cannot insert!!") ;
	}
	else
	{
		top++ ;
		stack[top] = value ;
	}
}
void evaluateTop(char op)
{
	switch(op)
	{
		case '+' : stack[top-1] = stack[top-1] + stack[top] ;
			   break ;
		case '-' : stack[top-1] = stack[top-1] - stack[top] ;
			   break ;
		case '*' : stack[top-1] = stack[top-1] * stack[top] ;
			   break ;
		case '/' : stack[top-1] = stack[top-1] / stack[top] ;
			   break ;
		//case '%' : stack[top] = stack[top-1]  stack[top] ;
		 //	   break ;
		default : printf("Enter valid operator!!") ;
	}
	top = top - 1 ;
}
void main()
{
	char postFix[SIZE] ;
	int i, value, k = 0 ;
	clrscr() ;
	printf("Enter a postfix expression: ") ;
	scanf("%s", postFix) ;
	for(i = 0 ; i < strlen(postFix) ; i++)
	{
		if(isalpha(postFix[i]))
		{
			printf("Enter the value of %c", 97+k) ;
			scanf("%d", &value) ;
			push(value) ;
			k++ ;
		}
		else
		{
			evaluateTop(postFix[i]) ;
		}
	}
	printf("\nThe answer after evaluation is: %d", stack[top]) ;
	getch() ;
}

