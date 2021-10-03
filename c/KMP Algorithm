//srishti1302
#include<stdio.h>
#include<string.h>
int failure[20];
void fail(char *pat)
{
	int i,j;
	int n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		while((pat[j]!=pat[i+1])&&(i>0))
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
	}
	for(int k=0;k<=n;k++)
        printf("%d\t",failure[k]);
}
int match(char *string, char *pat)
{
	int i=0,j=0;
	int lens=strlen(string);
	int lenp=strlen(pat);
	while(i<lens&&j<lenp)
	{
		if(string[i]==pat[j])
		{
			i++;
			j++;
		}
		else if(j==0)
			i++;
		else
			j=failure[j-1]+1;
	}
	return((j==lenp)?(i-lenp):-1);
}
void main()
{
	int i;
	char str[30],sub[20];
	printf("\nEnter a string\n");
	scanf("%s",str);
	printf("\nEnter a substring\n");
	scanf("%s",sub);
	fail(sub);
	i=match(str,sub);
	if(i==-1)
		printf("\nNot found");
	else
		printf("\nFound at position %d",i+1);

}
