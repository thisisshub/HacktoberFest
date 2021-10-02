#include <stdio.h>
main()
{
    

int ar[50];
int i,j,n,count[50];
int ct;
int total=0;
int total1=0,total2=0;
printf("enter no of elemets");
scanf("%d",&n);
printf("enter array");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);

for(i=0;i<n;i++)
{   ct=1;
    for(j=i+1;j<n;j++)
    {  
        if(ar[i]!= -1 && ar[j]!= -1)
        {
            
        
        if(ar[i]==ar[j])
        {
        ct++; 
        ar[j]=-1;
        }
        
        }
        
        
    }
count[i]=ct;

}

for(i=0;i<n;i++)
{
    

    if (count[i]!= 1)
    {
        if(count[i]%2==0)
        {total=total+(count[i]/2);
        
            
        }
        
        else 
        {total1=total1+(count[i]/2);
        }
            
    }
    else
    total2=0;
    
    
    
    total2=total +total1;
}
    

printf("%d",total2); 

}
