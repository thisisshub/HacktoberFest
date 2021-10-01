#include<stdio.h>
#include<math.h>
int main()
{
    float a, b, c;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);
    float D = ((b*b) - (4*a*c));
    if(a!=0)
    {
        if(D>=0)
        {
            float x1 = ( (-b) + (sqrt(D)) ) / (2*a);
            float x2 = ( (-b) - (sqrt(D)) ) / (2*a);
            if(D==0) printf("There is only one root: %f .\n", x1);
            else printf("The roots are: %f and %f and they are real. \n", x1, x2);
        }
        else
        {
            float real = (-b)/(2*a);
            float img = (sqrt(-D))/(2*a);
            printf("The roots are: (%f + %fi) and (%f - %fi) and they are imaginary. \n", real, img, real, img);
        }
    }
    else printf("Invalid Input. a cannot be 0.");
    return 0;
}