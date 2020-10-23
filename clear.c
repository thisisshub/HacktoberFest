#include<stdio.h>
#include<conio.h>

main()
{
   printf("\nPress any key to clear the screen.\n");

   getch();

   system("cls");

   printf("\nThis appears after clearing the screen.\n");
   printf("Press any key to exit...\n");

   getch();
   return 0;
}
