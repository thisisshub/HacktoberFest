#include<stdio.h>
int main()
{
	float a, c, r;
	
	printf("Enter value for radius = ");
	scanf("%f",&r);
	
	a= (22/7)*r*r;
	c= 2*(22/7)*r;
	printf("The area is = %f\n",a);
	printf("The circumference is = %f",c);
	
	return 0;
}
