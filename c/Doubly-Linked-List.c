//Program demonstrating the application of doubly linked list

/*Write an algorithm (using doubly linked list) and subsequent  C program for your algorithm, which inserts a new element between every pair of consecutive elements. 
The new element is the sum of its neighbors. For example, your  C code will produce output 12 46 34 90 56 134 78 93 15 80 65 137 72 for the input 12 34 56 78 15 65 72.*/

#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data; 
    
    struct Node* next;   // Pointer to next node in DLL 
    
    struct Node* prev; // Pointer to previous node in DLL 

}*head=NULL;  //Global structure variable

//Function to push into the doubly linked list
void push(int value){             
     //Create a new node
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	
	//set the value and the links
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(head==NULL)
      head=newnode;
      
    else
	{
        struct Node *temp=head;
        
        while(temp->next !=NULL)
            temp=temp->next;
            
        //Changing the links 
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
}

//Function to insert the sum in between the elements
void insertbetween(struct Node *prev_node,int value){
	//Creating a new node
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	
	//Set the value and the links for the new node
	newnode->data=value;
	newnode->next=prev_node->next;
	newnode->prev=prev_node;
	
	//Insert the node in between
	if (newnode->next != NULL) 
        newnode->next->prev = newnode; 
        
    prev_node->next=newnode;
}

//Function to compute the sum of 2 consecutive elements
void sum(){
	//Create a pointer
	struct Node *temp=head;
	
	int val;
	
	//Calculating the sum
	while(temp!=NULL && temp->next!=NULL){
		val=temp->data+temp->next->data;
		insertbetween(temp,val);
		temp=temp->next->next;
	}
}

//Function to display the final DLL
void display(){
	//Create a pointer
	struct Node *ptr=head;
	
	//Traverse through the nodes and print each of the node values
	while(ptr!=NULL){
		printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}


int main(){
	//Declare the necessary values
	int n,value,i;
	
	//Getting n which is the number of elements in the list
	printf("Enter the value of n:");
	scanf("%d",&n);
	
	//Getting the elements the elements of the list
	printf("\nEnter the elements of the list:\n");
	for(i=0;i<n;i++){
	   scanf("%d",&value);
	   //Push the element into he DLL
	   push(value);
	}
	
	sum();    //Function call to calculate the sum of consecutive elements
	
	printf("\n");
	printf("Final output:\n");
	
	display();  //Fucntion call to display the final list
}
