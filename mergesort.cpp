#include <bits/stdc++.h>
using namespace std;
class node{
public:
int data; // data field
struct node *next;
};
void display(class node* head){
node* current=head; // current node set to head
while(current!=NULL){ //traverse until current node isn't NULL
printf("%d ",current->data);
current=current->next; // go to next node
}
}
node* creatnode(int d){
node* temp=(node*)malloc(sizeof(node));
temp->data=d;
temp->next=NULL;
return temp;
}
node* mergeList(node* split1,node* split2){
//merging two sorted list
node* newhead=NULL;
//base cases
if(split1==NULL)
return split2;
if(split2==NULL)
return split1;
//recursively merge
if(split1->data<=split2->data){
newhead=split1;
newhead->next=mergeList(split1->next,split2);
}
else{
newhead=split2;
newhead->next=mergeList(split1,split2->next);
}
return newhead;
}
void splitList(node* head,node** split1,node** split2){
//similar to flyod's tortoise algorithm
node* slow=head;
node* fast=head->next;
while(fast!=NULL){
fast=fast->next;
if(fast!=NULL){
slow=slow->next;
fast=fast->next;
}
}
*split1=head;
*split2=slow->next;
//spliting
slow->next=NULL;
}
void mergeSort(node** refToHead){
node* head=*refToHead;
node* split1,*split2;
//base case
if(head==NULL || head->next==NULL){
return;
}
//split the list in two halves
splitList(head,&split1,&split2);
//recursively sort the two halves
mergeSort(&split1);
mergeSort(&split2);
//merge two sorted list
*refToHead=mergeList(split1,split2);
return;
}
int main(){
printf("creating the linked list by inserting new nodes at the end\n");
printf("enter 0 to stop building the list, else enter any integer\n");
int k,count=1,x;
node* curr,*temp;
scanf("%d",&k);
node* head=creatnode(k); //buliding list, first node
scanf("%d",&k);
temp=head;
///////////////////inserting at the end//////////////////////
while(k){
curr=creatnode(k);
temp->next=curr;//appending each node
temp=temp->next;
scanf("%d",&k);
}
cout<<"before merge sort...\n";
display(head); // displaying the list
cout<<"\nafter merge sort...\n";
mergeSort(&head);
display(head);
return 0;
}