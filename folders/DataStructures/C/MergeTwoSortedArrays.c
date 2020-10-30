// To merge two sorted arrays in one sorted array.
#include<stdio.h>
void sorted(int,int);
void main()
{
    int a[10],b[10],merge[20],i,j,as,bs;
    printf("Enter size of Array1 : ");
    scanf("%d",&as);
    for(i=0;i<as;i++)
    {
        scanf("%d",&a[i]);
    }
     printf("Enter size of Array2 : ");
    scanf("%d",&bs);
    for(i=0;i<bs;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(a,as);
    sort(b,bs);
    for(i=0;i<as;i++)
    {
        merge[i]=a[i];
    }
    for(i=0,j=as;i<bs,j<as+bs-1;i++,j++)
    {
        merge[j]= b[i];
    }
    sort(merge,as+bs);
    for(i=0;i<as+bs-1;i++)
    {
        printf("%d\t",merge[i]);
    }

}
int sort(int a[20], int size)
{
    int i,j,n;
    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            if(a[i]>a[j])
            {
                n=a[i];
                a[i]=a[j];
                a[j]=n;
            }
        }
    }
}
