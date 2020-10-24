/*
To perform the following Operations on String.
    1. Addition
    2. Copying
    3. Reverse
    4. Length of the String
*/
#include<stdio.h>
void addition(char s1[20],char s2[20])
{
    int i,j;
    char s3[20];
    for(i=0; s1[i]!='\0'; i++)
    {
        s3[i]=s1[i];
    }
    for(j=0; s2[j]!='\0'; j++)
    {
        s3[i]=s2[j];
        i++;
    }
    s3[i]='\0';
    printf("\n");
    puts(s3);
}
void copy(char s1[20],char s2[20])
{
    int i;
    for(i=0; s1[i]!='\0'; i++)
    {
        s2[i] = s1[i];
    }
    s2[i]='\0';
    printf("Original String = %s",s1);
    printf("Copied String = %s",s2);
}
void reverse(char s1[20],char s2[20])
{
    int i,j,k=0;
    for(i=0; s1[i]!='\0'; i++);
    for(j=i-1; j>=0; j--)
    {
        s2[k++]=s1[j];
    }
    s2[j]='\0';
    puts(s2);
}
int length(char s1[20])
{
    int i;
    for(i=1; s1[i]!='\0'; i++);
    printf("Length of String is: %d",i);
    return i;
}
void main()
{
    char s1[20],s2[20],s3[20];
    int choice,strno;
    printf("Enter String 1: ");
    gets(s1);
    printf("Enter String 2: ");
    gets(s2);
    do
    {
        printf("\n\nEnter 0 to exit.\n1. Concatenate\n2. Copy\n3. Reverse\n4. Length of String.\nEnter your Choice.");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addition(s1,s2);
            break;
        case 2:
        {
            printf("String 1 or String 2?");
            scanf("%d",&strno);
            if(strno==1)
            {
                copy(s1,s3);
            }
            else{
                if(strno==2)
                {
                    copy(s2,s3);
                }
                else
                {
                    printf("Enter either 1 or 2.");
                }
            }
            break;
        }
        case 3:
        {
            printf("String 1 or String 2?");
            scanf("%d",&strno);
            if(strno==1)
            {
                reverse(s1,s3);
            }
            else
            {
                if(strno==2)
                {
                    reverse(s2,s3);
                }
                else
                {
                    printf("Enter either 1 or 2.");
                }
            }
            break;
        }
        case 4:
        {
            printf("String 1 or String 2?");
            scanf("%d",&strno);
            if(strno==1)
            {
                length(s1);
            }
            else{
                if(strno==2)
                {
                    length(s2);
                }
                else
                {
                    printf("Enter either 1 or 2.");
                }
            }
            break;
        }
        case 0:
            break;
        default:{
            printf("Enter valid Choice.");
        }
        }
    }


    while(choice!=0);
}
