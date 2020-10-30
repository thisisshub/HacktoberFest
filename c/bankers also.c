#include<stdio.h>
void main()
{
int all[10][10],av[10],max[10][10],nd[10][10],i,j,n,m;
printf("enter number of processes");
scanf("%d",&n);
printf("enter number of resources");
scanf("%d",&m);
printf("enter allocation matrix");
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        scanf("%d",&all[i][j]);
    }
}
printf("enter max matrix");
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        scanf("%d",&max[i][j]);
    }
}
printf("enter available resources array");
for(i=0;i<m;i++)
{
    scanf("%d",&av[i]);
}
for (i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        nd[i][j]=max[i][j]-all[i][j];
        printf("%d",nd[i][j]);
    }
    printf("\n");
}
for(t=0;t<n;t++)
{
    for(i=0;i<n;i++)
    {
        if(fin[i]==0)
        {
            flag=0;
            for(j=0;j<n;j++)
            {
                if(nd[i][j]>av[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ss[c++]=i;
                fin[i]=1;
                for(k=0;k<m;k++)
                {
                    av[j]=av[j]+all[i][j];
                }
            }
        }
    }
}
}
