// Tree Traversal (In-order, Pre-order, Post-order)
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create()
{
    struct node *newn;
    int value;
    printf("Enter value(-1 for no data):");
    scanf("%d",&value);
    if(value==-1)
    {
        return NULL;
    }
    newn = malloc(sizeof(struct node));
    newn->data = value;

    printf("\nEnter left child of %d :\t",value);
    newn->left = create();

    printf("\nEnter right child of %d :\t",value);
    newn->right = create();

    return newn;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void main()
{
    struct node *t;
    t = create();
    printf("\n\n Inorder Traversal\n");
    inorder(t);
    printf("\n\nPreorder Traversal\n");
    preorder(t);
    printf("\n\nPostorder Traversal\n");
    postorder(t);

}
