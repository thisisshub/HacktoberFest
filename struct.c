#include <stdio.h>
#include <string.h>

struct abaikan
{
    char kerja[21];
};

main()
{
    struct abaikan lembur;

    strcpy(lembur.kerja, "Alasan Saja");

    printf("\n %s \n", lembur.kerja);
}
