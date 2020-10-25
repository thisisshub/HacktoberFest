#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    QUEUE queue;
    char op;
    int Elem;
    init(&queue); 
    do{
       printf("\n\nOPTIONS\n1-Insert element\n2-Pop element");
       printf("\n3-Print top \n4-Print queue\n5-Exit\n");
       scanf("%c",&op);  FLUSH;
       switch(op){
                 case '1':
                       printf("\nNew element: "); 
                       scanf("%d",&Elem); FLUSH;
                          if(insert(&queue, Elem)==0) 
                             printf("\nCannot insert new element %d",Elem); 
                       break;                   
                 case '2':
                       if(pop(&queue, &Elem)==0) printf("empty queue");
                       else printf("\nPoped element: %d", Elem);
                       break;
                  case '3':
                       if(read_top(queue, &Elem)==0) printf("empty queue");
                       else printf("\nTop of the queue: %d", Elem);
                       break;
                  case '4':
                       print_queue(queue);
                       break;
                  case '5': 
                        exit(0);
                  default:
                        printf("\nInvalid option");
       }
    }while(op!='s');
    
    exit (0);
}
