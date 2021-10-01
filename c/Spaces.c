// C Program to count the number of Blank Spaces, New lines and Tabs
#include<stdio.h>
#include <math.h>
#include <string.h>

void Counter(char* str)
{
	int space=0,tab=0,line=0;

	for(int i=0; str[i]!='\0'; i++)
	{
		if(str[i]=='\t')
		{
		    tab++;
		    printf("\\t");
		}
		else if(str[i]==' ')
		{
		    space++;
		    printf(" ");
		}
		else if(str[i]=='\n')
		{
		    line++;
		    printf("\\n");
		}
		else
        {
            printf("%c",str[i]);
        }
	}
	printf("\n Blank space = %d \n Tabs = %d \n New lines = %d ",space,tab,line);

}

int main()
{
	char str[100];
	printf("\n Enter a message ending in $ : ");
	scanf("%[^$]s",str);

	printf("\n Modified message : ");
	Counter(str);

	return 0;
}
