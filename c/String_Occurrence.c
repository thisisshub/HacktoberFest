// Program to check last occurrence of a character in a string
#include <stdio.h>
#include <string.h>

int occur(char str[], char c)
{
    int ind = -1;
    for(int i = 0; i <= strlen(str); i++)
  	{
  		if(str[i] == c)
		{
  			ind = i;
 		}
	}
    if(ind == -1)
  	{
  		printf("\n Character '%c'  not found in the String Input \n", c);
	}
	else
	{
		printf("\n The Last Occurrence of the Character '%c' is at position : %d \n", c, ind + 1);
	}
}

int main()
{
  	char str[100], ch;

  	printf("\n Please Enter a String :  ");
  	gets(str);

  	printf("\n Please Enter the Character to Check for :  ");
  	scanf("%c", &ch);

  	occur(str, ch);
  	return 0;
}
