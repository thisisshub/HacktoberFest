// C program to find if machine is little 
// endian or big endian. 
#include <stdio.h> 

int main() 
{ 
unsigned int n = 1; 
char *c = (char*)&n; 
if (*c)	 
	printf("LITTLE ENDIAN"); 
else
	printf("BIG ENDIAN"); 
return 0; 
} 
