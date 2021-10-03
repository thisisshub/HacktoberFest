#include<stdio.h>
int main()
{
	float C, F;
	
	printf("Enter Temp in F = ");
	scanf("%f",&F);
	
	C=(5.0/9.0)*(F-32.0);
	
	printf("Temp in C = %f",C);

	return 0;
}
