#include<stdio.h>
#include<math.h>
void main()
{
  int i,k=0,x[10],y[10],c[25],j,n,n1,d[25],f=0;
  printf("\n how many elements in SET 1:");
  scanf("%d",&n);
  printf("\n enter 1st SET elements");
  for(i=0;i<n;i++)
  {
     scanf("%d",&x[i]);
  }
  printf("\n how many elements in set 2:");
  scanf("%d",&n1);
  printf("\n enter 2st SET elements");
  for(i=0;i<n1;i++)
  {
     scanf("%d",&y[i]);
  }
  for(i=0;i<n;i++)
  {
     c[k]=x[i];
     k++;
  }
  for(i=0;i<n;i++)
  {
     for(j=0;j<n1;j++)
     {
        if(y[i]==x[j])
        break;
     }
     if(j==n)
     {
        c[k]=y[i];
        k++;
     }
  }
  printf("\n the union set is:{");
  for(i=0;i<k;i++)
  printf("%d",c[i]);
  printf("}\n");
  for(j=0;j<n;j++)
  {
     for(i=0;i<n1;i++)
     {
        if(y[i]==x[j])
        break;
     }
     if(i!=n1)
     {
        d[f]=y[i];
        f++;
     }
  }
  printf("\n the intersection set is :{");
  for(i=0;i<f;i++)
  printf("%d",d[i]);
  printf("}");
}
