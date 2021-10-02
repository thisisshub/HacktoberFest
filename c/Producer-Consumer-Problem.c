// C Program to solve producer consumer problem 
#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, item = 0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void Producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    item++;
    printf("\nProducer produced item %d.", item);
    mutex = signal(mutex);
}

void Consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumed item %d.", item);
    item--;
    mutex = signal(mutex);
}

void main()
{
    int ch;
    while (1)
    {
        printf("\nMenu\n1.Produce Item\n2.Consume Item\n3.Exit\nEnter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                Producer();
            else
                printf("\nBuffer is Full!!");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                Consumer();
            else
                printf("\nBuffer is Empty!!");
            break;
        case 3:
            exit(0);
            break;
        }
    }
}
