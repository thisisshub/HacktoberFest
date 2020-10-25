#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void init(QUEUE *q)
{
     *q = NULL;
}

int is_empty(QUEUE q)
{   
    if(q == NULL) return(1);
    else return(0);
}

void print_queue(QUEUE q){
    int i;
    QUEUE aux=q;
    if(is_empty(q)) printf("\nEmpty queue\n");
    else
    	while(aux != NULL)
        {
     		printf("\n%d", aux->info);
     		aux= aux->next;
        }
}

int insert(QUEUE *q, int Elem)
{
    QUEUE new;
    if((new = malloc(sizeof(struct NODE)))== NULL) 
            return(0);
    else
    {
        new->info = Elem;
        new->next = *q;
        *q = new;
        return(1);
 
    }
}

int pop(QUEUE *q, int *Elem)
{
    QUEUE aux;
    if(is_empty(*q)) return(0);
    else
    {
         printf("Desempliha");
         *Elem = (*q)->info;
         aux = *q;
         *q = aux->next;
         
         free(aux);
    }
    return(1);
}

int read_top(QUEUE pilha, int *top)
{
    if(is_empty(pilha)) return(0);
    else{
         *top = pilha->info;
         return(1);
         }
}
