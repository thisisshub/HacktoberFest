#include<bits/stdc++.h>
using namespace std;


/*balanced binary tree can be implemented using array
a node at index 'x' ...index of left subtree is '2x' and index of right subtree is '2x+1' 
In other tree, lot of space wastage.
*/

// Tree is recursive data structure ... 'n' nodes => 'n-1' edges

struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;

}; 

// BST does all operations in O(log n) time in average case nd O(n) in worst case...but we can avoid worst case by ensuring tree is always balanced :)

struct bstnode* getnaya(int data){
    bstnode* naya=new bstnode();
    naya->data=data;
    naya->left=naya->right=NULL;
    return naya;
}

bstnode* insert(bstnode* root,int data){
    if(root==NULL){
        root=getnaya(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

bool search(bstnode* root,int data){

    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<root->data) return search(root->left,data);
    else return(search(root->right,data));

}

bstnode* find(bstnode* root,int data){
    if(root==NULL) return NULL;
    else if(root->data==data) return root;
    else if(data<root->data) return find(root->left,data);
    else return find(root->right,data);
}

void inOrder(bstnode* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void preOrder(bstnode* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(bstnode* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

struct bstnode* get_successor(struct bstnode* root,int data){

    struct bstnode* cur=find(root,data);
    if(cur==NULL) return NULL;
    else if(cur->right!=NULL){
        struct bstnode* temp=cur->right;
        while (temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp;
        
    }
    else{
        struct bstnode* ancestor=root;
        struct bstnode* succesor=NULL;
        while (ancestor!=cur)
        {
            if(cur->data<=ancestor->data){
                succesor=ancestor;
                ancestor=ancestor->left;
            }
            else ancestor=ancestor->right;
        }
        return succesor;
    }

}


int main(){

    
   
    struct bstnode* root=NULL; // root pointer nd not root
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);

    cout<<"In order : ";
    inOrder(root);
    cout<<endl;
    cout<<"Pre order : ";
    preOrder(root);
    cout<<endl;
    cout<<"Post order : ";
    postOrder(root);
    cout<<endl;

    // int n;cout<<"Num : ";
    // cin>>n;
    // if(search(root,n)) cout<<"Ok\n";
    // else cout<<"Nah\n";
    bstnode* successor=get_successor(root,10);
    cout<<"Successor of 10: "<<successor->data<<"\n";


}
