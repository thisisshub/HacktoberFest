/*_________________________SWEETY______________________________*/
#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node *next;

};

struct Node *head;


void printList(){

    struct Node* cur=head;

    if(head==NULL){
        printf("Empty list!!!\n");
    }

    while (cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    
}


void createNode(int n_data){
    
    struct Node *naya_node=(struct Node*)malloc(sizeof(struct Node));
    
    naya_node->data=n_data;
    naya_node->next=NULL;
    
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
    }

}


void insertAtBeginning(int n_data){

    struct Node* naya_node=(struct Node*)malloc(sizeof(struct Node));
    
    naya_node->data=n_data;
    naya_node->next=head;

    head=naya_node;

}


void insertAtEnd(int n_data){
    
    struct Node* naya_node=(struct Node*)malloc(sizeof(struct Node));
    naya_node->data=n_data;

    if(head==NULL){
        head=naya_node;
    }
    else{
        struct Node *req=head;
        while (head->next!=NULL)
        {
            head=head->next;
        }
        head->next=naya_node;
        head=req;
    }

}


void insertAtPos(int pos,int n_data){

    struct Node* naya_data=(struct Node*)malloc(sizeof(struct Node));
    naya_data->data=n_data;

    struct Node* cur=head;
    if(pos==0){
        insertAtBeginning(n_data);
    }
    else{

        for(int i=0;i<(pos-1);i++){

            cur=cur->next;
            
        }
        naya_data->next=cur->next;
        cur->next=naya_data;
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

printf("Linked List contains : ");
printList();  

int t1,t2,t3,t4,t5,t6;


printf("\nIf you want to insert node at the beginning...press 1, otherwise 0 : ");
scanf("%d",&t1);
if(t1){
    printf("Enter the data you want to insert : ");
    scanf("%d",&n_data);
    insertAtBeginning(n_data);
} 

printf("Linked List contains : ");
printList();


printf("\nIf you want to insert node at the end...press 1, otherwise 0 : ");
scanf("%d",&t2);
if(t2){
    printf("Enter the data you want to insert : ");
    scanf("%d",&n_data);
    insertAtEnd(n_data);
} 

printf("Linked List contains : ");
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

printf("Linked List contains : ");
printList();


printf("\n");

return 0;

}




