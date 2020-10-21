// A simple inorder traversal based  
// program to convert a Binary Tree to DLL  
#include <bits/stdc++.h> 
using namespace std; 
  
// A tree node  
class node  
{  
    public: 
    int data;  
    node *left, *right;  
};  
  
// A utility function to create 
// a new tree node  
node *newNode(int data)  
{  
    node *Node = new node(); 
    Node->data = data;  
    Node->left = Node->right = NULL;  
    return(Node);  
}  
  
// Standard Inorder traversal of tree  
void inorder(node *root)  
{  
    if (root != NULL)  
    {  
        inorder(root->left);  
        cout << "\t" << root->data;  
        inorder(root->right);  
    }  
}  
  
// Changes left pointers to work as  
// previous pointers in converted DLL  
// The function simply does inorder  
// traversal of Binary Tree and updates  
// left pointer using previously visited node  
void fixPrevPtr(node *root)  
{  
    static node *pre = NULL;  
  
    if (root != NULL)  
    {  
        fixPrevPtr(root->left);  
        root->left = pre;  
        pre = root;  
        fixPrevPtr(root->right);  
    }  
}  
  
// Changes right pointers to work  
// as next pointers in converted DLL  
node *fixNextPtr(node *root)  
{  
    node *prev = NULL;  
  
    // Find the right most node  
    // in BT or last node in DLL  
    while (root && root->right != NULL)  
        root = root->right;  
  
    // Start from the rightmost node,  
    // traverse back using left pointers.  
    // While traversing, change right pointer of nodes.  
    while (root && root->left != NULL)  
    {  
        prev = root;  
        root = root->left;  
        root->right = prev;  
    }  
  
    // The leftmost node is head  
    // of linked list, return it  
    return (root);  
}  
  
// The main function that converts  
// BST to DLL and returns head of DLL  
node *BTToDLL(node *root)  
{  
    // Set the previous pointer  
    fixPrevPtr(root);  
  
    // Set the next pointer and return head of DLL  
    return fixNextPtr(root);  
}  
  
// Traverses the DLL from left tor right  
void printList(node *root)  
{  
    while (root != NULL)  
    {  
        cout<<"\t"<<root->data;  
        root = root->right;  
    }  
}  
  
// Driver code  
int main(void)  
{  
    // Let us create the tree  
    // shown in above diagram  
    node *root = newNode(10);  
    root->left = newNode(12);  
    root->right = newNode(15);  
    root->left->left = newNode(25);  
    root->left->right = newNode(30);  
    root->right->left = newNode(36);  
  
    cout<<"\n\t\tInorder Tree Traversal\n\n";  
    inorder(root);  
  
    node *head = BTToDLL(root);  
  
    cout << "\n\n\t\tDLL Traversal\n\n";  
    printList(head);  
    return 0;  
} 