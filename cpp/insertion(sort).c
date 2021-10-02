#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[10000],i,n;
    printf("Enter Value of N:",&n);
    scanf("%d",&n);
    printf("Enter Elements in array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr, n);
    printf("Sorted Elements in array:\n");
    print(arr, n);
}
