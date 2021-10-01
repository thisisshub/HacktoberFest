// Recursion for fibonacci 
#include<stdio.h>

void fibo_series(int x, int y, int terms, int count);

int main()
{
    printf("\n How many terms: ");
    int n,count=1;
    scanf("%d", &n);
    printf("\n Fibonacci Series is:\n ");
    fibo_series(0,1,n,count);
    return 0;
}

void fibo_series(int x, int y, int terms, int count)
{
    printf("   %d", x);
    if(count<terms)
    {
        fibo_series(y,x+y,terms, count+1);
    }
}
