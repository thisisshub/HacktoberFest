#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
           }
       }
   }  
       
void displayArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++){
         printf("%d ", arr[i]);
    }   
    printf("\n");
}
 
int main()
{
    int arr[] = {30, 34, 25, 10, 32, 11, 99};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    displayArray(arr, n);
    return 0;
}