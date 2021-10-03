#include <stdio.h>

int main()
{
    int n;
    int key, temp, j;
    puts("Enter size of an array");
    scanf("%d", &n);
    int arr[n];
    puts("Enter elements of an array");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    puts("");
    //sorting
    for (int i = 0; i < n; ++i)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
            arr[j + 1] = key;
        }
    }
    //printing
    puts("Sorted elements of an array :");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
