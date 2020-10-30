#include <stdio.h>
 
int main()
{
   int m, n, c, d, first[10][10], second[10][10], difference[10][10];
 
   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d", &m, &n);
   printf("Enter the elements of first matrix\n");
 
   for (c = 0; c < m; c++)
     for (d = 0 ; d < n; d++)
       scanf("%d", &first[c][d]);
 
   printf("Enter the elements of second matrix\n");
 
   for (c = 0; c < m; c++)
     for (d = 0; d < n; d++)
         scanf("%d", &second[c][d]);
 
   printf("Difference of entered matrices:-\n");
 
   for (c = 0; c < m; c++) {
     for (d = 0; d < n; d++) {
       difference[c][d] = first[c][d] - second[c][d];
       printf("%d\t",difference[c][d]);
     }
     printf("\n");
   }
 
   return 0;
}
