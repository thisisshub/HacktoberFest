#include "queue.h"

int main(){
    QUEUE queue;
    char op;
    int Elem;
    init(&queue); 
    do{
      printf("\n\nOPTIONS\n1-Insert element\n2-Pop element");
       printf("\n3-Print queue\nE-Exit\n");
       scanf("%c",&op);  FLUSH;
       switch(op){
                 case '1':
                       printf("\n New element: "); 
                       scanf("%d",&Elem); FLUSH;
                          if(insert(&queue, Elem)==0) 
                             printf("\nCannot insert the new element %d\nThe queue is full", Elem); 
                       break;                   
                 case '2':
                       if(pop(&queue, &Elem)==0) printf("\nEmpty queue");
                       else printf("\nPoped element: %d", Elem);
                       break;
                  case '3':
                       print_queue(&queue);
       }
    } while(op!='E');

    exit(0);
}