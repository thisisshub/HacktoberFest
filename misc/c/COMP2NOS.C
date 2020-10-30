// C program to check if two numbers are equal 
// without using arithmetic operators or 
// comparison operators 
#include<stdio.h> 

int main() 
{ 
int x = 10; 
int y = 10; 
if ( !(x ^ y) ) 
	printf(" x is equal to y "); 
else
	printf(" x is not equal to y "); 
return 0; 
} 
