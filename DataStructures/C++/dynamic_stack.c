#include <stdio.h>
#include<malloc.h>

void push();
void pop();
void display();

struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;

void main() {
  int choice;
    char ch;
    do{
        printf("\n 1.push");
        printf("\n 2.pop");
        printf("\n 3.display");
        printf("\n enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
        }
        printf("\n do u want to continue: ");
        scanf("%c",&ch);
        scanf("%c",&ch);
        
    }
    while(ch=='y');
    
}

void push(){ 
    struct node *temp=(struct node*)malloc(sizeof(struct node*)); 
    if (temp==NULL) {
        printf("Overflow"); 
    } 
    else{
        printf("enter the node: ");
        scanf("%d",&temp->data);
        temp->next = top; // put top pointer reference into temp link 
        top = temp; 	// make temp as top of stack 
    } 
}
void pop(){ 
    struct node* temp; 
    if (top == NULL) {  // check for stack underflow  
        printf("\nStack Underflow"); 
    } 
    else { 
        temp = top; // top assign into temp 
        top = top->next; // assign second node to top 
        free(temp); // release memory of top node 
    } 
} 
void display(){ 	
    struct node *temp=top;
    if (top == NULL){ 
        printf("\n Stack is empty"); 
    } 
    else{
        while(temp!=NULL){ 
            printf("\n %d",temp->data);
            temp=temp->next;
        }
    }
}
