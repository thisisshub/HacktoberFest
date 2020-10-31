#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    int coeff;
    struct node *next;
}Node;

Node *criaLista(){
    return NULL;
}

Node *criaNode(int num,int coeff){
    Node *ptr;
    if(!(ptr=(Node *)malloc(sizeof(Node)))) return NULL;
    ptr->num=num;
    ptr->coeff=coeff;
    ptr->next=NULL;
    return ptr;
}

Node *inserePolinomio(Node *lst,Node *poly){
    Node *aux;
    if(!poly) return lst;
    if(!lst) return poly;
    for(aux=lst;aux->next;aux=aux->next);
    aux->next=poly;
    return lst;
}

void imprimePolinomio(Node *lst){
    if(!lst) printf("Lista vazia!");
    while(lst){
        printf("+");
        printf("(");
        printf("%d",lst->num);
        printf("^");
        printf("%d",lst->coeff);
        printf(")");
        lst=lst->next;
    }
}

Node *somaPolinomio(Node *poly1,Node *poly2,Node *poly3){
    Node *aux;
    if(!poly1 || !poly2) return NULL;
    for(poly1,poly2;(poly1 && poly2);){
        if(poly1->coeff > poly2->coeff){
            aux=criaNode(poly1->num,poly1->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly1=poly1->next;
            continue;
        }
        if(poly2->coeff > poly1->coeff){
            aux=criaNode(poly2->num,poly2->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly2=poly2->next;
            continue;
        }
        if(poly1->coeff == poly2->coeff){
            aux=criaNode(poly1->num+poly2->num,poly1->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    if(!poly1 && poly2){
        while(poly2){
            aux=criaNode(poly2->num,poly2->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly2=poly2->next;
        }
    }
    if(!poly2 && poly1){
        while(poly1){
            aux=criaNode(poly1->num,poly1->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly1=poly1->next;
        }
    }
    return poly3;
}

Node *subtraiPolinomio(Node *poly1,Node *poly2,Node *poly3){
    Node *aux;
    if(!poly1 || !poly2) return NULL;

    for(poly1,poly2;(poly1 && poly2);){
        if(poly1->coeff > poly2->coeff){
            aux=criaNode(poly1->num,poly1->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly1=poly1->next;
            continue;
        }
        if(poly2->coeff > poly1->coeff){
            aux=criaNode(poly2->num,poly2->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly2=poly2->next;
            continue;
        }
        if(poly1->coeff == poly2->coeff){
            aux=criaNode(poly1->num-poly2->num,poly1->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    if(!poly1 && poly2){
        while(poly2){
            aux=criaNode(poly2->num,poly2->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly2=poly2->next;
        }
    }
    if(!poly2 && poly1){
        while(poly1){
            aux=criaNode(poly1->num,poly1->coeff);
            poly3=inserePolinomio(poly3,aux);
            poly1=poly1->next;
        }
    }
    return poly3;
}

Node *multiplicaPolinomio(Node *poly1,Node *poly2,Node *poly3){
    Node *aux,*aux2=NULL,*aux3=NULL,*auxPoly1=poly1,*auxPoly2=poly2,*auxPoly22=poly2;
    for(auxPoly1,poly2;auxPoly1 && poly2;){
        if(poly1==auxPoly1){
            aux=criaNode(poly1->num*poly2->num,poly1->coeff+poly2->coeff);
            aux2=inserePolinomio(aux2,aux);
            if(!auxPoly1->next && !poly2->next) return aux2; //caso exista apenas um termo nos dois polinomios
            if(!auxPoly1->next && poly2->next || poly2->next){
                poly2=poly2->next;
                continue;
            }
            auxPoly1=auxPoly1->next;
            continue;
        }
        else{
            aux=criaNode(auxPoly1->num*auxPoly2->num,auxPoly1->coeff+auxPoly2->coeff);
            aux3=inserePolinomio(aux3,aux);
            if(auxPoly2->next){
                auxPoly2=auxPoly2->next;
                continue;
            }
            if(!auxPoly1->next) break;
            auxPoly1=auxPoly1->next;
            //auxPoly2=auxPoly22; ERRO
        }
    }
    poly3=somaPolinomio(aux2,aux3,poly3);
    return poly3;
}

Node *dividePolinomio(Node *poly1,Node *poly2,Node *poly3){
    Node *auxPoly1=poly1,*auxQuoc,*auxResto,*auxRestoSoma=NULL;
    if(!poly1 || !poly2) return NULL;
    for(auxPoly1;auxPoly1;){
        auxRestoSoma=NULL;
        auxQuoc=criaNode(auxPoly1->num/poly2->num,auxPoly1->coeff-poly2->coeff);
        poly3=inserePolinomio(poly3,auxQuoc);
        auxQuoc->num=-auxQuoc->num;
        auxResto=multiplicaPolinomio(auxQuoc,poly2->next,auxResto);
        auxRestoSoma=somaPolinomio(auxPoly1->next,auxResto,auxRestoSoma);
        auxQuoc->num=-auxQuoc->num;
        auxPoly1=auxRestoSoma;
        if(auxPoly1->coeff == 0 || auxPoly1->coeff < poly2->coeff) break; //verifica se é resto
    }
    return poly3;
}

int main(){
    Node *lst=criaLista();
    Node *first=criaNode(1,1);
    Node *second=criaNode(2,0);
    //Node *third=criaNode(1,1);
    //Node *fourth=criaNode(-6,0);
    //Node *five=criaNode(-1,0);
    lst=inserePolinomio(lst,first);
    lst=inserePolinomio(lst,second);
    //lst=inserePolinomio(lst,third);
    //lst=inserePolinomio(lst,fourth);
    //lst=inserePolinomio(lst,five);
    imprimePolinomio(lst);
    printf("\n");

    Node *lst0=criaLista();
    Node *first1=criaNode(1,3);
    Node *second2=criaNode(4,2);
    Node *third3=criaNode(1,1);
    Node *fourth4=criaNode(-6,0);
    lst0=inserePolinomio(lst0,first1);
    lst0=inserePolinomio(lst0,second2);
    lst0=inserePolinomio(lst0,third3);
    lst0=inserePolinomio(lst0,fourth4);
    imprimePolinomio(lst0);
    printf("\n");

    Node *lst1=criaLista();
    lst1=multiplicaPolinomio(lst0,lst,lst1);
    imprimePolinomio(lst1);
    return 1;
}
