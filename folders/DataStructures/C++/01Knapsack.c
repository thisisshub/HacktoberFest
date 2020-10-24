#include<stdio.h>
int max(int, int);
void main()
{
    int w[100],p[100],W,n,i,j,table[100][100],tp=0,si[100];
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the Weight of bag :");
    scanf("%d",&W);
    printf("Enter the weight and profits : ");
    w[0]=0;
    p[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        scanf("%d",&p[i]);
    }
	for(i=0;i<=n;i++)
	{
		si[i]=0;
	}
    for(i=1;i<=n;i++)
    {
        table[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(j<w[i])
            {
                table[i][j]=table[i-1][j];
            }
            else if(j>=w[i])
            {
                table[i][j]=max(table[i-1][j],(p[i]+table[i-1][j-w[i]]));
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    i=n;
    j=W;
    while(table[i][j]!=0)
    {
        if(table[i][j]==table[i-1][j-1])
        {
            i--;
            j--;
        }
        else
        {
            tp=tp+p[i];
			si[i]=1;
            if(j<w[i])
            {
                i=i-1;
            }
            else
            {
                i--;
                if(table[i-1][j]<(p[i]+table[i-1,j-w[i]]))
                {
                    j=j-w[i];
                }
				else
				{
					j=j;
				}
            }
        }
    }
	printf("Total Profit: %d\n",tp);
	printf("Selected items: ( ");
	for(i=1;i<n;i++)
	{
		printf("%d\t",si[i]);
	}
	printf("%d)",si[i]);
}
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
