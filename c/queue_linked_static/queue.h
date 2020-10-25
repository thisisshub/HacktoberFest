#include <stdio.h>
#include <stdlib.h>

#define MAX 15
#define FLUSH while(getchar()!='\n')

typedef struct{
        char node[MAX];
        int top;
        } QUEUE;

void init(QUEUE *q);

int is_empty(QUEUE *P);

int is_full(QUEUE *q);

void print_queue(QUEUE *q);

int insert(QUEUE *q, int Elem);

int pop(QUEUE *q, int *Elem);
        
int read_top(QUEUE *q, int *top);