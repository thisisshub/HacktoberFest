#include <stdio.h>

// Question - https://www.geeksforgeeks.org/move-zeroes-end-array/?ref=lbp

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int array[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int arraySize = sizeof(array)/sizeof(array[0]);

    for (int i = 0; i < arraySize; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[i] == 0) {
                swap(&array[j], &array[i]);
            }
        }
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d\n", array[i]);
    }
}