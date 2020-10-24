// To search an element in the array using Recursive Binary Search.
#include<stdio.h>
int recursion(int ar[],int low,int high,int value)
{
    int mid = (low+high)/2;
    if(low>high)
    {
        return -1;
    }
    else
    {
        if(value==ar[mid])
        {
            printf("Element found at position %d.",mid);
            return mid;
        }
        else
        {
            if(value<ar[mid])
            {
                recursion(ar,low,mid-1,value);
            }
            else
            {
                if(value>ar[mid])
                {
                    recursion(ar,mid+1,high,value);
                }
            }
        }
    }
}
void main()
{
    int ar[20],high,low,value,size,i,index;
    printf("Enter the size of Array:");
    scanf("%d",&size);
    printf("Enter %d elements.",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("Enter value to be searched.");
    scanf("%d",&value);
    low=0;
    high = size-1;
    index = recursion(ar,low,high,value);
    if(index<0)
    {
        printf("Element not found.");
    }

}
