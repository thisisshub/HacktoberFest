// To search an element in the 2-Dimensional Array using Linear Search.
#include<stdio.h>
void main()
{
    int a[10][10],i,j,m,n,value,f=0;
    printf("Enter no. of rows in array: ");
    scanf("%d",&m);
    printf("Enter no. of columns in array: ");
    scanf("%d",&n);
    printf("Enter %d elements : ",m*n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter element to be searched.");
    scanf("%d",&value);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(value == a[i][j])
            {
                printf("The element if found at Row:%d and Column:%d",i,j);
                f=1;
            }
        }

    }
    if(f==0){
        printf("Element not found.");
    }

}
