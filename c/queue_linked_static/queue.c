#include "queue.h"

void init(QUEUE *q)
{
     q->top = -1;
}

int is_empty(QUEUE *P)
{   
    if(P->top == -1) return(1);
    else return(0);
}

int is_full(QUEUE *q)
{
    if(q->top == MAX-1) return(1);
    else return(0);
}

void print_queue(QUEUE *q){
    int i;
    if(q->top == -1) printf("\nEmpty\n");
    else
    	for(i=(q->top);i>=0;i--)
        {
     		printf("\n%i", q->node[i]);
        }
}

int insert(QUEUE *q, int Elem)
{
     if(is_full(q) == 1) return(0);
     else
     {
          q->top++;
          q->node[q->top]= Elem;
     }
 return(1);
}

int pop(QUEUE *q, int *Elem)
{
    if(is_empty(q)) return(0);
    else
    {
         *Elem = q->node[q->top];
         q->top--;
    }
    return(1);
}

int read_top(QUEUE *q, int *top)
{
    if(is_empty(q)) return(0);
    else{
         *top = q->node[q->top];
         return(1);
         }
}

     
