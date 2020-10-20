#include<iostream>
using namespace std;


struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start=nullptr;

struct node *create(struct node *start){

    cout<<"\n enter number -1 to quit ";
    int num;

    while(1){
        cin>>num;
        if(num==-1)
            break;


        struct node *new_node=(struct node *)malloc(sizeof(struct node));

        new_node->data=num;


        if(start==nullptr){
            start=new_node;
            new_node->prev=nullptr;
            new_node->next=nullptr;
        }
        else{
            struct node *ptr=start;

            while(ptr!=nullptr){
                ptr=ptr->next;
            }
            new_node->prev=ptr;
            new_node->next=nullptr;
        }
    }
    return start;
}

struct node *display(struct node *start){

    struct node *ptr=start;
    cout<<"\n printing data\n";
    while(ptr!=nullptr){
        cout<<"\t"<<ptr->data;
        ptr=ptr->next;
    }

    return start;
}

struct node *searchList(struct node *start){

    struct node *ptr=start;

    while(ptr!=nullptr){
        
    }

}

int main(){

    cout<<"\n Doubly linked list ";
    int choice=0;

    while(1){
        cout<<"\n 1.Create";
        cout<<"\n 2.Dispaly";
        cout<<"\n 3.Search";
        cout<<"\n 4.Delete";
        cout<<"\n";

        cin>>choice;

        if(choice==-1)
            break;
        if(choice==1)
            start=create(start);
        if(choice==2)
            start=display(start);
        if(choice==3)
            start=searchList(start);
        if(choice==4)
            start=delete_node(start); 
        
    }


    return 0;
}