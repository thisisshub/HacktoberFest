#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp = 0;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            comp++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            comp++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int size, x, *arr;
    FILE *fp;
    comp = 0;

    while (1)
    {
        printf("Enter the size of array :\n");
        scanf("%d", &size);
        arr = (int *)malloc(size * sizeof(int));
        srand(time(0));
        printf("Press :\n1)To Select Numbers Randomly.\n2)To Select Uniformaly distributed numbers\n3)To select Normaly distributed numbers\n4)To Break\n");
        scanf("%d", &x);
        if (x == 1)
        {
            int k;
            printf("Enter the range of the Numbers :\n");
            scanf("%d", &k);
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % k;
            }
        }
        if (x == 2)
        {
            fp = fopen("Uniform_dist.txt", "r");
            for (int i = 0; i < size; i++)
            {
                fscanf(fp, "%d", &arr[i]);
            }
        }
        if (x == 3)
        {
            fp = fopen("Normal_dist.txt", "r");
            for (int i = 0; i < size; i++)
            {
                fscanf(fp, "%d", &arr[i]);
            }
        }
        if (x == 4)
        {
            break;
        }
        printf("The Unsorted numbers in array are\n");
        printArray(arr, size);
        mergeSort(arr, 0, size - 1);
        printf("\nThe sorted array is :\n");
        printArray(arr, size);
        printf("\n\nThe number of comparisions are %d\n", comp);
    }
}