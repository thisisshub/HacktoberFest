#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long guess[10];
    int nextGuess = 0;

    int iSecret, iGuess;

    /* initialize random seed: */
    srand(time(NULL));

    /* generate secret number between 1 and 10: */
    iSecret = rand() % 31 + 1;

    // printf("%d\n", iSecret);

    do
    {
        printf("Guess the number (1 to 31): ");
        scanf("%d", &iGuess);
        if (iSecret < iGuess)
            puts("The secret number is lower");
        else if (iSecret > iGuess)
            puts("The secret number is higher");

        guess[nextGuess++] = iGuess;
    } while (iSecret != iGuess && nextGuess < 10);
    if (iSecret == iGuess)
    {
        puts("Congratulations!");
    }
    else
    {
        puts("Sorry! Better luck next time.");
    }

    printf("You've tried:\n");
    for (int i = 0; i < nextGuess; i++)
    {
        printf("%d ", guess[i]);
    }
    printf("\nComputer secret number: %d", iSecret);

    return 0;
}
