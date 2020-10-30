#include<stdio.h>
#include<conio.h>
main()
{
    int i,j;
    char s1[100],s2[100];
    printf("enter the strings");
    scanf("%s",&s1);
    scanf("%s",&s2);
    for(i=0;s1[i]!='\0';++i)
{

}

    for(j=0;s2[j]!='\0';++j)
{

}
    int a[256],temp1[i],l,temp[j],e;
  for(e=0;e<256;e++)
  {
      a[e]=0;
  }
   if(i!=j)
   {
       printf("no");
   }
else
{

    for(l=0;l<i;l++)
    {
        temp1[l]=s1[l];
        a[temp1[l]]=a[temp1[l]]+1;
            }

        for(l=0;l<i;l++)
    {
        temp[l]=s2[l];
        a[temp[l]]=a[temp[l]]-1;
            }



int flag=0;
for(i=0;i<256;i++)
{
    if(a[i]!=0)
    {
       flag=1;

    }

}
if(flag==1)
{
    printf("not an annagram");
}

else{
    printf("hhaha annagram");




}
}
}
