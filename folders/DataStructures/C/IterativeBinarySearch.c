// To search an element in the array using Iterative Binary search.

#include<stdio.h>
void main()
{
    int ar[20],i,j,mid,high,low,size,value,k=0;
    printf("Enter size of array:");
    scanf("%d",&size);
    printf("Enter %d elements in ascending order:",size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&ar[i]);
    }
    low=0;
    high=size-1;
    mid = (low + high)/2;
    printf("Enter value to be searched.");
    scanf("%d",&value);

    for(i=0; low<=high; i++)
    {
        if(value==ar[mid])
        {
            printf("Element %d found at position %d.",value,mid);
            k=1;
            break;
        }
        else
        {
            if(value<ar[mid])
            {
                high = mid-1;
                mid = (low+high)/2;

            }
            else
            {
                if(value>ar[mid])
                {
                    low = mid+1;
                    mid = (low+high)/2;
                }
            }
        }

    }
    if(k==0)
    {
       printf("Element not found.");
    }


}
