#include<iostream>
#include<malloc.h>
using namespace std;


struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;



struct node *display(struct node *start){
    struct node *ptr=start;
if(start==NULL)
    cout<<"\n List does not exist";
else{
    cout<<"\n printig the list   ";
    while(ptr!=NULL){       // if use ptr->next!=NULL miss out last node since its next is null so use this while(ptr!=NULL) or use while(1) and break at if(ptr->next==NULL)
        cout<<" -> "<<ptr->data;
        ptr=ptr->next;
    }
}
    return start;
}


// create func can also be later used to insert node after reaminig nodes 
struct node *create(struct node *start){

int num;
cout<<"\n enter data to insert ";
cout<<"\n enter -1 to quit ";

while(1){
    cin>>num;

    if(num==-1){
        cout<<"\n QUITTING num is -1";
    break;
    }
        
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
            new_node->data=num;
        if(start==NULL){
            start=new_node;
            new_node->next=NULL;
        }
        else{
            struct node *ptr=start;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=new_node;
                new_node->next=NULL;
            
        }
}

    display(start);
    return start;
}

struct node *insert_beg(struct node *start){

    struct node *new_node=(struct node *)malloc(sizeof(struct node));

    int data;
    cout<<"\n Enter data of node ";
    cin>>data;

    new_node->data=data;

    new_node->next=start;
    start=new_node;

    display(start);
    return start;
}
/*****************************************************************
 *                    Causes Crash System
 *  OOM killer of linux terminal saves the computer after a long time
struct node *insert_before(struct node *start){

    struct node *ptr=start;

cout<<"\n enter before which elemnet u want to insert ";
    int elem;
    cin>>elem;

cout<<"\n enter the number to insert ";
    int data;
    cin>>data;

  struct node *pre_ptr=ptr;

while(ptr!=NULL){

    pre_ptr=ptr;
    if(ptr->data==elem){

        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=data;
        pre_ptr->next=new_node;
        new_node->next=ptr;
    }
    ptr=ptr->next;
}  
  
  /*
    struct node *pre_ptr=ptr;

    //using count++ locate      // multiple occurences?
    // or using ptr++ locate

    while(ptr->next!=NULL){
           pre_ptr=ptr;
           ptr=ptr->next;
           if(ptr->data==elem){
                cout<<"\n element found ";
                break;
           }
               
    }

    struct node *new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data=data;
    pre_ptr->next=new_node;
    new_node->next=ptr;

/
    display(start);
    return start;
}
*/

struct node *insert_end(struct node *start){

    struct node *ptr=start;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    cout<<"\n enter data of node ";
    int data;
    cin>>data;

struct node *new_node=(struct node*)malloc(sizeof(struct node));
    ptr->next=new_node;
    new_node->data=data;

    ptr->next=new_node;
    new_node->next=NULL;

    display(start);
    return start;
}


struct node *search_List(struct node *start){

    struct node *ptr=start;
    cout<<"\n enter value to search";

    int find;
    cin>>find;
    int node_position=0;
    int flag=0;
    while(ptr!=NULL){
        if(ptr->data==find){
            cout<<"\n Found at Node "<<node_position<<" and index "<<node_position+1;
            flag=1;
        }
        node_position++;
        ptr=ptr->next;
    }
    if(flag==0)
        cout<<"\n Not Found element";

    display(start);
    return start;
}
struct node *insert_after(struct node *start){

        struct node *ptr=start;

        cout<<"\n enter element after which you want to insert";
        int insertAfter;
        cin>>insertAfter;
        cout<<"\n Ennter value to insert ";
        int value_to_insert;
        cin>>value_to_insert;

        while(ptr!=NULL){

                if(ptr->data==insertAfter){
                    cout<<"\n data mathced";

        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=value_to_insert;
        new_node->next=ptr->next;
        ptr->next=new_node;
                    // break;       // to include multiple occurecences dont write break;
                    // aslo creation of node done inside loop for multiple occurence match case
                }

            ptr=ptr->next;
        }


    display(start);
    return start;
}



// Works for mulitple occurenecs
struct node *insert_before(struct node *start){

    struct node *ptr=start;

    struct node *pre_ptr=start; 

    cout<<"\n WARNING cannot insert before first node casues Program to Crash";

cout<<"\n enter before which elemnet u want to insert ";
    int elem;
    cin>>elem;

cout<<"\n enter the number to insert ";
    int num;
    cin>>num;


while(ptr!=NULL){
    
    if(ptr->data==elem && ptr==start){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;

        new_node->next=start;
        start=new_node;

    }
    else if(ptr->data==elem){

        cout<<"\n Found node  >>>>>>>> inserting before it ";
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        
        new_node->data=num;
    
        pre_ptr->next=new_node;    // if try insert_before on first node pre_ptr fails since leads to self loop also below ptr leads to self loop on first node
                // SOLVED first case problem using above if condition
        new_node->next=ptr;
    }
    pre_ptr=ptr;
  
    ptr=ptr->next;
}
    display(start);
    return start;
}

struct node *delete_beg(struct node *start){

    struct node *ptr=start;
    start=NULL;
    ptr=ptr->next;
    start=ptr;

    display(start);

    return start;
}

struct node *delete_end(struct node *start){

struct node *ptr=start;
struct node *pre_ptr=start;
while(ptr->next!=NULL){
    pre_ptr=ptr;
    ptr=ptr->next;
}

pre_ptr->next=NULL;

display(start);

    return start;
}


// can use global falg return=0 so that when print list dont allow to print
struct node *delete_list(struct node *start){

    start=NULL;
    /*
        struct node *ptr=start;

        while(ptr!=NULL){
            free(ptr);
            ptr=prt->next;
        }

    */

    display(start);

    return start;
}


// works for mulitple occurences
struct node *delete_node(struct node *start){

struct node *ptr=start;
struct node *before_ptr=start;

display(start);

cout<<"\n enter which node to delete ";
int node_to_delete;
cin>>node_to_delete;

while(ptr!=NULL){

    if(ptr->data==node_to_delete && ptr==start){
        ptr=ptr->next;
        start=ptr;
    }
    else if(ptr->data==node_to_delete){
        before_ptr->next=ptr->next;
    }
    before_ptr=ptr;
    ptr=ptr->next;

}
cout<<"\n List after Deleteion\n";
display(start);
    return start;
}
int main(){
cout<<"\n\n";
    int choice=0;


    do{

    cout<<"\n   *************** Singly Linked list *********************";
    cout<<"\n 1.create()";
    cout<<"\n 2.display() ";
    cout<<"\n 3.insert beg()";
    cout<<"\n 4.insert end()";
    cout<<"\n 5.search list()";
    cout<<"\n 6.insert after()";
    cout<<"\n 7.insert before()";
    cout<<"\n 8. delete beg()";
    cout<<"\n 9. delete end()";
    cout<<"\n 10. delete list()";
    cout<<"\n 11. delete node()";

cout<<"\n\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            start=create(start);
            break;
        case 2:
            start=display(start);
            break;
        case 3:
            start=insert_beg(start);
            break;
        case 4:
            start=insert_end(start);
            break;
        case 5:
            start=search_List(start);
            break;
        case 6:
           start=insert_after(start);
            break;
        case 7:
            start=insert_before(start);
            break;
    
        case 8:
            start=delete_beg(start);
            break;
        case 9:
            start=delete_end(start);
            break;
        case 10:
            start=delete_list(start);
            break;
        case 11:
            start=delete_node(start);
            break;
    
        default:
            break;  
        }   
    }while(choice!=13);    

    cout<<"\n\n";
    return 0;
}