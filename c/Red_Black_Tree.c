#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
    struct node *next[2]; //lchild,rchild,,parent
    int data, color;

} node;
enum n_color
{
    red,
    black
};
//int red = 0;
//int black = 1;
node *root = NULL;

node *create_node(int x)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = x;
    ptr->color = red;
    ptr->next[0] = NULL;
    ptr->next[1] = NULL;
    return ptr;
}
void insert(int data)
{
    node *stack[98];
    node *ptr, *newnode, *xptr, *yptr;
    int index = 0;
    int a[98], height = 0;
    ptr = root;
    if (!root)
    {
        root = create_node(data);
        return;
    }
    stack[height] = root;
    a[height++] = 0;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("Duplicates data are not allowed\n");
            return;
        }
        index = (data - ptr->data) > 0 ? 1 : 0;
        stack[height] = ptr;
        ptr = ptr->next[index];
        a[height++] = index;
    }
    stack[height - 1]->next[index] = newnode = create_node(data);
    while (height >= 3 && stack[height - 1]->color == red)
    {
        if (a[height - 2] == 0)
        {
            yptr = stack[height - 2]->next[1];
            if (yptr != NULL && yptr->color == red)
            {
                stack[height - 2]->color = red;
                stack[height - 1]->color = yptr->color = black;
                height = height - 2;
            }
            else
            {
                if (a[height - 1] == 0)
                {
                    yptr = stack[height - 1];
                }
                else
                {
                    xptr = stack[height - 1];
                    yptr = xptr->next[1];
                    xptr->next[1] = yptr->next[0];
                    yptr->next[0] = xptr;
                    stack[height - 2]->next[0] = yptr;
                }
                xptr = stack[height - 2];
                xptr->color = red;
                yptr->color = black;
                xptr->next[0] = yptr->next[1];
                yptr->next[1] = xptr;
                if (xptr == root)
                {
                    root = yptr;
                }
                else
                {
                    stack[height - 3]->next[a[height - 3]] = yptr;
                }
                break;
            }
        }
        else
        {
            yptr = stack[height - 2]->next[0];
            if ((yptr != NULL) && (yptr->color == red))
            {
                stack[height - 2]->color = red;
                stack[height - 1]->color = yptr->color = black;
                height = height - 2;
            }
            else
            {
                if (a[height - 1] == 1)
                {
                    yptr = stack[height - 1];
                }
                else
                {
                    xptr = stack[height - 1];
                    yptr = xptr->next[0];
                    xptr->next[0] = yptr->next[1];
                    yptr->next[1] = xptr;
                    stack[height - 2]->next[1] = yptr;
                }
                xptr = stack[height - 2];
                yptr->color = black;
                xptr->color = red;
                xptr->next[1] = yptr->next[0];
                yptr->next[0] = xptr;
                if (xptr == root)
                {
                    root = yptr;
                }
                else
                {
                    stack[height - 3]->next[a[height - 3]] = yptr;
                }
                break;
            }
        }
    }
    root->color = black;
}
void delete (int data)
{
    node *stack[98];
    node *ptr, *xptr, *yptr;
    node *pptr, *qptr, *rptr;
    int a[98];
    int height = 0, diff, i;
    enum n_color color;

    if (!root)
    {
        printf("Tree not available\n");
        return;
    }

    ptr = root;
    while (ptr != NULL)
    {
        if ((data - ptr->data) == 0)
        {
            break;
        }
        diff = (data - ptr->data) > 0 ? 1 : 0;
        stack[height] = ptr;
        a[height++] = diff;
        ptr = ptr->next[diff];
    }

    if (ptr->next[1] == NULL)
    {
        if ((ptr == root) && (ptr->next[0] == NULL))
        {
            free(ptr);
            root = NULL;
        }
        else if (ptr == root)
        {
            root = ptr->next[0];
            free(ptr);
        }
        else
        {
            stack[height - 1]->next[a[height - 1]] = ptr->next[0];
        }
    }
    else
    {
        xptr = ptr->next[1];
        if (xptr->next[0] == NULL)
        {
            xptr->next[0] = ptr->next[0];
            color = xptr->color;
            xptr->color = ptr->color;
            ptr->color = color;

            if (ptr == root)
            {
                root = xptr;
            }
            else
            {
                stack[height - 1]->next[a[height - 1]] = xptr;
            }

            a[height] = 1;
            stack[height++] = xptr;
        }
        else
        {
            i = height++;
            while (1)
            {
                a[height] = 0;
                stack[height++] = xptr;
                yptr = xptr->next[0];
                if (!yptr->next[0])
                    break;
                xptr = yptr;
            }

            a[i] = 1;
            stack[i] = yptr;
            if (i > 0)
                stack[i - 1]->next[a[i - 1]] = yptr;

            yptr->next[0] = ptr->next[0];

            xptr->next[0] = yptr->next[1];
            yptr->next[1] = ptr->next[1];

            if (ptr == root)
            {
                root = yptr;
            }

            color = yptr->color;
            yptr->color = ptr->color;
            ptr->color = color;
        }
    }

    if (height < 1)
        return;

    if (ptr->color == black)
    {
        while (1)
        {
            pptr = stack[height - 1]->next[a[height - 1]];
            if (pptr && pptr->color == red)
            {
                pptr->color = black;
                break;
            }

            if (height < 2)
                break;

            if (a[height - 2] == 0)
            {
                rptr = stack[height - 1]->next[1];

                if (!rptr)
                    break;

                if (rptr->color == red)
                {
                    stack[height - 1]->color = red;
                    rptr->color = black;
                    stack[height - 1]->next[1] = rptr->next[0];
                    rptr->next[0] = stack[height - 1];

                    if (stack[height - 1] == root)
                    {
                        root = rptr;
                    }
                    else
                    {
                        stack[height - 2]->next[a[height - 2]] = rptr;
                    }
                    a[height] = 0;
                    stack[height] = stack[height - 1];
                    stack[height - 1] = rptr;
                    height++;

                    rptr = stack[height - 1]->next[1];
                }

                if ((!rptr->next[0] || rptr->next[0]->color == black) &&
                    (!rptr->next[1] || rptr->next[1]->color == black))
                {
                    rptr->color = red;
                }
                else
                {
                    if (!rptr->next[1] || rptr->next[1]->color == black)
                    {
                        qptr = rptr->next[0];
                        rptr->color = red;
                        qptr->color = black;
                        rptr->next[0] = qptr->next[1];
                        qptr->next[1] = rptr;
                        rptr = stack[height - 1]->next[1] = qptr;
                    }
                    rptr->color = stack[height - 1]->color;
                    stack[height - 1]->color = black;
                    rptr->next[1]->color = black;
                    stack[height - 1]->next[1] = rptr->next[0];
                    rptr->next[0] = stack[height - 1];
                    if (stack[height - 1] == root)
                    {
                        root = rptr;
                    }
                    else
                    {
                        stack[height - 2]->next[a[height - 2]] = rptr;
                    }
                    break;
                }
            }
            else
            {
                rptr = stack[height - 1]->next[0];
                if (!rptr)
                    break;

                if (rptr->color == red)
                {
                    stack[height - 1]->color = red;
                    rptr->color = black;
                    stack[height - 1]->next[0] = rptr->next[1];
                    rptr->next[1] = stack[height - 1];

                    if (stack[height - 1] == root)
                    {
                        root = rptr;
                    }
                    else
                    {
                        stack[height - 2]->next[a[height - 2]] = rptr;
                    }
                    a[height] = 1;
                    stack[height] = stack[height - 1];
                    stack[height - 1] = rptr;
                    height++;

                    rptr = stack[height - 1]->next[0];
                }
                if ((!rptr->next[0] || rptr->next[0]->color == black) &&
                    (!rptr->next[1] || rptr->next[1]->color == black))
                {
                    rptr->color = red;
                }
                else
                {
                    if (!rptr->next[0] || rptr->next[0]->color == black)
                    {
                        qptr = rptr->next[1];
                        rptr->color = red;
                        qptr->color = black;
                        rptr->next[1] = qptr->next[0];
                        qptr->next[0] = rptr;
                        rptr = stack[height - 1]->next[0] = qptr;
                    }
                    rptr->color = stack[height - 1]->color;
                    stack[height - 1]->color = black;
                    rptr->next[0]->color = black;
                    stack[height - 1]->next[0] = rptr->next[1];
                    rptr->next[1] = stack[height - 1];
                    if (stack[height - 1] == root)
                    {
                        root = rptr;
                    }
                    else
                    {
                        stack[height - 2]->next[a[height - 2]] = rptr;
                    }
                    break;
                }
            }
            height--;
        }
    }
}

void inorder(node *node)
{
    if (node)
    {
        inorder(node->next[0]);
        printf("%d  ", node->data);
        inorder(node->next[1]);
    }
    return;
}
int main()
{
    int ch, data;
    while (1)
    {
        printf("Red-Black Tree\n");
        printf("-----------------------\n");
        printf("1) For Inertion of Elements  2) Deletion of Elements 3) Display the elements in Inorder Traversal 4) For exit \n");
        printf("\nEnter your choice number:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert:\n");
            scanf("%d", &data);
            insert(data);
            printf("The element is Successfully Inserted\n");
            break;
        case 2:
            printf("Enter the element to delete from the Tree:\n");
            scanf("%d", &data);
            delete (data);
            printf("The elemented is Successfully Deleted\n");
            break;
        case 3:
            printf("The Inorder Traversal of the Red-Black Tree\n");
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Please enter valid choice number\n");
            break;
        }
        printf("\n");
    }
    return 0;
}