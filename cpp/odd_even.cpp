#include <stdio.h>
#include <stdlib.h>

int main()
{
    // printf - output
    // scanf - input
    int range;

    printf("Enter number range: ");

    // scanf: parameter
    //   value: %d
    //   variable: variable_name
    //   ex: scanf("%d", &variable_name)
    scanf("%d", &range);

    // for loop: parameter
    //   starting value
    //   range
    //   process increment/decrement
    for (int number = 1; number <= range; number++)
    {
        if (number % 2 == 0)
        {
            printf("%d is an even number\n", number);
        }
        else
        {
            printf("%d is an odd number\n", number);
        }
    }

    return 0;
}
