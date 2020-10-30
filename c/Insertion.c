#include <stdio.h>

 void insert(int array[], int n, int position, int value)
 {
     for (int c = n - 1; c >= position - 1; c--)
      array[c+1] = array[c];

   array[position-1] = value;

   printf("Resultant array is\n");

   for (int c = 0; c <= n; c++)
      printf("%d\t", array[c]);
 }

int main()
{
   int array[100], position, c, n, value;
   printf("Enter number of elements in array: ");
   scanf("%d", &n);

   printf("Enter %d elements: ", n);

   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);

   printf("Enter the location where you wish to insert an element: ");
   scanf("%d", &position);

   printf("Enter the value to insert: ");
   scanf("%d", &value);

   insert(array,n,position,value) ;
   return 0;
}
