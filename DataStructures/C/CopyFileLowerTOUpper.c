// To copy one file to another converting all lowercase to uppercase.
#include<stdio.h>

int main()
{
    FILE *fptr1 , *fptr2;
    char fn1[100],fn2[100],ch;
    //printf("Enter name of source file:");
    //gets(fn1);
    //fn1 = 'MrNimeshSolanki';
    //printf("Enter name of destination file:");
    //gets(fn2);
    //fn2 = 'CopiedFile';
    fptr1 = fopen("A.txt","r");
    fptr2 = fopen("C.txt","w");
    if(fptr1==NULL)
    {
        printf("File is Empty.");
        return 0;
    }
    ch = fgetc(fptr1);
    while(ch!=EOF)
    {
        if(ch>='a' && ch<='z')
        {
            ch = ch-32;
        }
        fputc(ch,fptr2);
        ch = fgetc(fptr1);
    }
        printf("File Copied.");
        fclose(fptr1);
        fclose(fptr2);
        return 1;
}
