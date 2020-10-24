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

void reverseList(){

    if(head!=NULL && head->next!=NULL){

        struct Node *pre=head;
        struct Node *cur=head->next;
        struct Node *n=NULL;
        while (cur!=NULL)
        {
            struct Node *tmp=cur->next;
            cur->next=pre;
            pre->next=n;
            n=pre;
            pre=cur;
            cur=tmp;
        }
        head=pre;

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

reverseList();
printf("\nReversed Linked List : ");
printList();

printf("\n");

return 0;

}




