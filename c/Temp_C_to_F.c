#include<stdio.h>
int main()
{
	float c, f;
	
	printf("Enter Temp in c = ");
	scanf("%f",&c);
	
	f=(9.0/5.0*c)+32.0;
	
	printf("Temp in f = %.2f",f);

	return 0;
}
