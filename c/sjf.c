#include<stdio.h>
main()
{
int at[10], bt[10],b[10], n, i, j, wt[10], tat[10],t=0,s;
float atat=0, awt=0 ,sum =0,sumw=0;
printf("enter the number of processes");
scanf("%d",&n);
printf("enter the arrival times");
for (i=0;i<n;i++)
    scanf("%d",&at[i]);
    printf("enter the burst times");
for(i=0;i<n;i++)
   {
    scanf("%d",&bt[i]);
    b[i]=bt[i];
   }
for(i=0;i<n;i++)
{   int min=500;
    for(j=0;j<n;j++)
    {
        if(bt[j]<min && bt[j]>0 && at[j]<=t)
        {
            s=j;
            min=b[j];
        }
    }
        t=t+bt[s];
        tat[s]=t-at[s];
        wt[s]=tat[s]-bt[s];
        bt[s]=0;

    }

for (i=0;i<n;i++)
{
    printf("%d \t %d \t %d \t %d",at[i],b[i],tat[i],wt[i]);
    printf("\n");
}
for(i=0;i<n;i++)
{
    sum = sum + tat[i];
    sumw= sumw + wt[i];
}
atat= sum/n;
awt= sumw/n;

printf("atat = %f and awt= %f",atat, awt);
}
