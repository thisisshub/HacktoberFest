#include<stdio.h>

int main()
{
    float cel, far;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &cel);
    far = (1.8*cel) + 32;
    printf("Temperature in farenheit is: %.2f\n", far);
    return 0;
}