#include<stdio.h>

int main()
{
    printf("Enter N : ");
    int N;
    scanf("%d", &N);
    int a = 0, b = 1, c = 0;
    printf("The first %d terms of the fibonacci series are: \n", N);
    for(int i=1; i<=N; i++)
    {
        printf("%d ", c);
        a = b;
        b = c;
        c = (a+b);
    }
    return 0;
}