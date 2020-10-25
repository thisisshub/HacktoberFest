#include <iostream>

using namespace std;

struct node
{
    int data;          // Data of node
    struct node *next; // Address of the next node
} * stnode;

void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if (stnode == NULL)
    {
        printf("Memory can not be allocated.");
    }
    else
    {
        // Adding data for the node
        printf("Input data for node 1: ");
        scanf("%d", &num);
        stnode->data = num;
        stnode->next = NULL;
        tmp = stnode;

        for (i = 2; i <= n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if (fnNode == NULL)
            {
                printf("Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Input data for node %d: ", i);
                scanf("%d", &num);

                fnNode->data = num;
                fnNode->next = NULL;

                tmp->next = fnNode;
                tmp = tmp->next;
            }
        }
    }
}

void displayList()
{
    struct node *tmp;
    if (stnode == NULL)
    {
        printf("List is empty");
    }
    else
    {
        tmp = stnode;
        while (tmp != NULL)
        {
            printf("Data = %d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

void reverseList()
{
    struct node *prevNode, *curNode;
    if (stnode != NULL)
    {
        prevNode = stnode;
        curNode = stnode->next;
        stnode = stnode->next;

        prevNode->next = NULL; //convert the first node as last
        while (stnode != NULL)
        {
            stnode = stnode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = stnode;
        }
        stnode = prevNode; //convert the last node as head
        displayList();
    }
}

int main()
{
    createNodeList(5);
    displayList();
    reverseList();

    return 0;
}
