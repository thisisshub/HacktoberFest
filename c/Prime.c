#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n)
{
    int i;

    if(n <= 1)
    return false;

    for(i=2;i<n;i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}



int main()
{
    int n = 23;

    if(isPrime(n))
    printf("%d is a Prime Number",n);

    else
    printf("%d is not a Prime Number",n);

    return 0;
}
