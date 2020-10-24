#include<stdio.h>

double e(double x, double n)
{
    static double p=1,f=1;
    double r;
    if (n==0)
    {
        return 1;
    }
    
    else
    {
        r=e(x,n-1);
        p=p*x;
        f=f*n;

        return r+(p/f);
    }
    
}

int main()
{
    double a,b;
    printf("Enter the digit of whose taylor series you want");
    scanf("%lf",&a);
    printf("Enter the number of terms");
    scanf("%lf",&b);
    printf("the sum of taylor series is %lf", e(a,b) );

    return 0;
}
