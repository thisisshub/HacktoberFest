#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* link;
};
node* head=NULL;
void insert_at_head(int d){
    node *ptr = new node();
    ptr->data =d;
    ptr->link=head;
    head=ptr;
}
void insert_at_end(int d){
    node *ptr =new node();
    ptr->data=d;
    ptr->link=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        node* temp =head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=ptr;
    }
}
void delete_at_head(){
    if(head==NULL){
        cout<<"LIST IS EMPTY"<<endl;
    }
    else{
        
        node *ptr =head;
        head=head->link ;
        free(ptr);
    }
}
void delete_at_end(){
    node *prev,*ptr;
    if(head=NULL){
        cout<<"LIST IS EMPTY"<<endl;
    }
    else if(head->link=NULL){
        ptr=head;
        head=NULL;
        free(ptr);
    }
    else{
        ptr=head;
        while (ptr->link!=NULL){
            prev= ptr;
            ptr=ptr->link;
        }
        prev->link=NULL;
        free(ptr);
    }
}
void middle_element(){
    node *slow=head;
    node *fast=head;
    if(head==NULL){
        cout<<"LIST IS EMPTY";
    }
    else{
    while(fast!=NULL&&fast->link!=NULL){
        slow=slow->link;
        fast=fast->link->link;
    }
    cout<<"THE MIDDLE ELEMENT IS : " <<slow->data<<endl;
    }
}
void reverse_a_linked_list(){
    node *p,*c,*n;
    c=head;
    p=NULL;
    while(c!=NULL){
        n=c->link;
        c->link=p;
        p=c;
        c=n;
    }
    head=p;
}
void odd_even(){
    node *first = head;
    node *second =head->link;
    node *first_next =head;
    node *second_next = head->link;
    while(second && second->link){
        first->link =first->link->link;
        second->link =second->link->link;
        first =first->link;
        second =second->link;
    }
    first->link = second_next;
    
    
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
return 0;
}