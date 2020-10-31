#include<stdio.h>

int factorial(int number)
{
    if(number == 0)
        return 1;
    else
        return(number*factorial(number - 1));
}
int main()
{
    int n, num;
    printf("Enter no. to find factorial: ");
    scanf("%d", &n);
    if (n>0)
        num = factorial(n);
    else
        printf("Please enter a positive integer number");
    printf("%d! = %d", n, num);
}
