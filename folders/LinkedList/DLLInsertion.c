#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{

    int data;
    struct Node *next;
    struct Node *prev;

};

struct Node *head;

void printList(){

  struct Node* var=head;

  if(head==NULL){
    printf("Empty list !!!");
  }

  while (var!=NULL)
    {
        printf("%d ",var->data);
        var=var->next;
    }

}

void createNode(int n_data){

  struct Node *naya_node=(struct Node*)malloc(sizeof(struct Node));
  naya_node->data=n_data;
  naya_node->next=NULL;
  naya_node->prev=NULL;

  if(head==NULL){
    head=naya_node;
  }
  else{
    struct Node *var=head;
    while (var->next!=NULL)
    {
        var=var->next;
    }
    var->next=naya_node;
    naya_node->prev=var;
    
  }

}


void insertAtBeginning(int n_data){

    struct Node *naya_node=(struct Node*)malloc(sizeof(struct Node));
    
    naya_node->data=n_data;
    head->prev=naya_node;
    naya_node->next=head;
    naya_node->prev=NULL;

    head=naya_node;

}


void insertAtEnd(int n_data){

  struct Node* naya_node=(struct Node*)malloc(sizeof(struct Node));
  naya_node->data=n_data;

  if(head==NULL){
    head=naya_node;
  }
  else{

    struct Node *var=head;
    while (var->next!=NULL)
    {
        var=var->next;
    }
    var->next=naya_node;
    naya_node->prev=var;
    
  }

}


void insertAtPos(int pos,int n_data){

  struct Node* naya_data=(struct Node*)malloc(sizeof(struct Node));
  naya_data->data=n_data;

  if(pos==0){
    insertAtBeginning(n_data);
  }

  else{

    struct Node *tmp=head;

    for(int i=0;i<pos-1;i++){
      tmp=tmp->next;
    }
    struct Node *var=tmp->next;
    tmp->next=naya_data;
    naya_data->prev=tmp;
    naya_data->next=var;

    if(var!=NULL){
      var->prev=naya_data;
    }

  }

}


int main(){

  int n;
  printf("Enter the number of nodes you want to insert : ");
  scanf("%d",&n);
    
  int n_data;


  for(int i=0;i<n;i++){
      printf("Enter the data you want to insert : ");
      scanf("%d",&n_data);
      createNode(n_data);
  }  

  printf("Doubly Linked List contains : ");
  printList(); 


  int t1,t2,t3,t4,t5,t6;

  
  printf("\nIf you want to insert node at the beginning...press 1, otherwise 0 : ");
  scanf("%d",&t1);
  if(t1){
      printf("Enter the data you want to insert : ");
      scanf("%d",&n_data);
      insertAtBeginning(n_data);
  } 

  printf("Doubly Linked List contains : ");
  printList();

  
  printf("\nIf you want to insert node at the end...press 1, otherwise 0 : ");
  scanf("%d",&t2);
  if(t2){
      printf("Enter the data you want to insert : ");
      scanf("%d",&n_data);
      insertAtEnd(n_data);
  } 

  printf("Doubly Linked List contains : ");
  printList();

  
  printf("\nIf you want to insert a node anywhere between first and last node..press 1, otherwise 0 : ");
  scanf("%d",&t3);
  int pos;
  if(t3){
      printf("Enter the position at which you want to insert node (0-based indexing) : ");
      scanf("%d",&pos);
      printf("Enter the data you want to insert : ");
      scanf("%d",&n_data);
      insertAtPos(pos,n_data);
  } 

  printf("Doubly Linked List contains : ");
  printList();
    
  return 0;

}

