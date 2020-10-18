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


void deleteAtBeginning(){

    head=head->next;

}


void deleteAtEnd(){

    struct Node* pre=head;
    struct Node* cur=head->next;
    while (cur->next!=NULL)
    {
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    

}


void deleteAtPos(int x){

    struct Node* pre=head;
    struct Node* cur=head->next;

    if(x==0){
        deleteAtBeginning();
    }
    
    else{
        for(int i=0;i<(x-1);i++){
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
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

printf("\nIf you want to delete node at the beginning...press 1, otherwise 0 : ");
scanf("%d",&t4);
if(t4){
    deleteAtBeginning();
}

printf("Linked List contains : ");
printList();


printf("\nIf you want to delete node at the end...press 1, otherwise 0 : ");
scanf("%d",&t5);
if(t5){
    deleteAtEnd();
} 

printf("Linked List contains : ");
printList();


printf("\nIf you want to delete a node anywhere between first and last node..press 1, otherwise 0 : ");
scanf("%d",&t6);
int x;
if(t6){
    printf("Enter the position at which you want to delete node (0-based indexing) : ");
    scanf("%d",&x);
    deleteAtPos(x);
} 

printf("Linked List contains : ");
printList();


printf("\n");

return 0;

}




