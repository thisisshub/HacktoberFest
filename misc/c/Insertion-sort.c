#include <math.h> 
#include <stdio.h> 

void insertionSort(int arr[], int n) 
{ 
    int i, p, j; 
    for (i = 1; i < n; i++) { 
        p = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > p) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = p; 
    } 
} 
  
void show(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int arr[10],n,i;
    printf("\nEnter the size: ");
    scanf("%d",&n);
    printf("\n Enter the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
  
    insertionSort(arr, n); 
    show(arr, n); 
  
    return 0; 
} 
