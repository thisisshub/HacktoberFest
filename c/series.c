
#include <stdio.h>

int main()
{
    int a, x,i,n,sum=1;
    long long fact=1;
    printf("enter the number");
    scanf("%d",&n);
     printf("enter the x");
    scanf("%d",&x);
   
    while(x>=1)
    {
    fact=fact*x;
    x--;
}

for (i=2;i<=n;i++)
{

    sum=sum+fact/i;
   
    
}
 printf("sum is %d",sum);
return 0;
}

