#include<stdio.h>
main()
{
int a,b;
printf("enter two numbers");
scanf("%d%d",&a,&b);
if (a & ~b == 1)
    printf("%d is greater than %d",a,b);
else if(~a&b == 1)
        printf("%d is greater than %d",b,a);
else
        printf("same numbers");
}
