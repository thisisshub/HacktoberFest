#include <stdio.h>

void main()
{
    int n,a,r=0;
    int c = n;
    printf("enter any value of n");
    scanf("%d",&n);
    while(n>=1)
    {
        a=n%10;
        r=r*10+a;
        n=n/10;
    }
    printf("reverse=%d",r);
    if(r=c)
    {
        printf("yes no. is pallindrome");
    }
    else
    {
        printf("not a pallindrome");
    }
  }

