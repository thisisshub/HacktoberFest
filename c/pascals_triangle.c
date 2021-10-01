#include<stdio.h>

int factorial(int num)
{
    int fact = 1;
    for(int i=1; i<=num; i++) fact *= i;
    return fact;
}

int main()
{
    printf("Enter N : ");
    int N;
    scanf("%d", &N);
    int sp = (N-1);
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=sp; j++) printf(" ");
        sp--;
        for(int j=0; j<i; j++)
        {
            int comb = factorial(i-1)/(factorial(j)*factorial(i-1-j));
            printf("%d ", comb);
        }
        printf("\n");
    }
    return 0;
}