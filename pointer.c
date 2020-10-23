#include <stdio.h>

main()
{
    int *px, y;
    px = &y;

    printf("\n Masukkan Nilai Anda = ");
    scanf("%d", &y);
    printf(" Nilai Anda %d \n", *px);
}
