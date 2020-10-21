//Count number of leaves in a binary tree.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
int count = 0;
struct node *create()
{
    struct node *newn;
    int value;
    printf("Enter data (-1 for no data):");
    scanf("%d",&value);
    if(value==-1)
    {
        return NULL;
    }
    newn = malloc(sizeof(struct node));
    newn->data = value;

    printf("Enter left child of %d.\t",value);
    newn->left = create();

    printf("Enter right child of %d.\t",value);
    newn->right = create();

    return newn;
};
int check(struct node *leaf)
{
    if(leaf->left == NULL && leaf->right == NULL)
    {
        count++;
        return count;
    }
    else
    {
        if(leaf->left!=NULL)
            check(leaf->left);
        if(leaf->right!=NULL)
            check(leaf->right);
    }
}
void main()
{
    struct node *t;
    t = create();
    int leaves;
    leaves = check(t);
    printf("Number of Leaves are %d.",leaves);
}
