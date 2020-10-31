//AUTHOR-ANURAG SINGH;DATE-07-09-19;PURPOSE-UDEMY CHALLENGE 7-RANDOM NO.GUESSING GAME//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main ()
{
  time_t t;
  srand ((unsigned) time (&t));//Seeding rand() using time variable
  int randomnum = rand () % 21;//variable declarations//
  int numberoftries = 3;
  int guess;
  int i;
  char name[20];

  printf("This is a guessing game!I have chosen a number between 0 to 20 which you have to guess!!!You will get %d tries for doing so!\n\n\n",numberoftries);
  printf("Hey player,enter your name:\n\n");
  scanf("%s",&name);
   for (i = numberoftries; i > 0; i--)//a for loop for taking user input until he guess correctly
   {
      printf("Hey %s!Enter your guess:",name);//user inputs his guess
      scanf("%d",&guess);
      if(guess==randomnum)
      {
         break;
      }

        else if (guess < randomnum)
	    {
	      printf
		("Oops!Thats not correct!My number is more than that!\n\n");
		printf("You still have %d tr%s remaining!\n\n",(i-1),((i-1)==1)?"y":"ies");
	    }
	  else if (guess > randomnum)
	    {
	      printf ("Oops!Thats not correct!My number less than that!\n\n");
	      printf("You still have %d tr%s remaining!\n\n",(i-1),((i-1)==1)?"y":"ies");
	    }
    }
	if(i>0)//if we dont want to use thsi if,we could have written return instead of break in the if(guess==randomnum) condition!!//
{
    printf("You won!");
}
else

    {
        printf("OOPS!You ran out of tries!Better luck next time!\n\n");
        printf("Btw the number was %d",randomnum);
        }
return 0;
}
