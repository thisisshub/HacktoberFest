#include <stdio.h>
#include <stdlib.h>

struct node
{

        int data;
        struct node* left;
        struct node* right;
};
struct node *create(value)
{
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
};
struct node* left(struct node* root, int value)
{
    root->left = create(value);
    return root->left;
};
struct node* right(struct node* root, int value)
{
    root->right = create(value);
    return root->right;
};
void inorder(struct node* p)
{

    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void preorder(struct node* p)
{

    if(p!=NULL)
    {
        printf("%d ",p->data);
        inorder(p->left);
        inorder(p->right);
    }
}
void postorder(struct node* p)
{

    if(p!=NULL)
    {
        inorder(p->left);
        inorder(p->right);
        printf("%d ",p->data);
    }
}
int add(struct node* p)
{
    int sum;
       if (p == NULL)
       {
           return 0;
       }
    return (p->data + add(p->left) + add(p->right));
}
void main()
{
    struct node *root = create(1);
    left(root,2);
    right(root,3);
    left(root->left,4);
    right(root->left,5);
    left(root->right,6);
    right(root->right,7);
    printf("\n\nIn-order\n");
    inorder(root);
    printf("\n\nPre-order\n");
    preorder(root);
    printf("\n\nPost-order\n");
    postorder(root);
    printf("\n");
    printf("\n\n");
    int sum = add(root);
    printf("Sum : %d",sum);
}
