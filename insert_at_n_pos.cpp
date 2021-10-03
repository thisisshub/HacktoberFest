#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};


node * insert(node * head,int data)
{
    node *temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;
    if( head == NULL)
	    head = temp1;
    else {
	    node *temp = head;
	    while(temp->next != NULL)
		    temp = temp->next;
	    temp->next = temp1;
	    temp1->next = NULL;
    }
    return head;
}


node * insert_at_n(node *head, int data, int pos)
{
    node *ptr = new node();
    ptr->data = data;
    int i;
    node *temp = head;
    if (pos == 1)
    {
        ptr->next = temp;
        head = ptr;
        return head;
    }

    for (i = 1; i <= pos - 2; i++)
        temp = temp->next;

    ptr->next = temp->next;
    temp->next = ptr;

    return head;

}

void display(node *head)
{
    node *temp = head;
    cout << "list is :-";
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }

}

int main()
{
	node *head = NULL;
    int i, n, pos, data;
    cout << "enter the number of nodes: ";
    cin >> n;
    cout << "enter the data for nodes : ";
    for (i = 0; i < n; i++)
    {
        cin >> data;
        head = insert(head, data);
    }
    display(head);
    cout << "\n insert the data you want to insert :-";
    cin >> data;
    cout << "enter the position where you want to insert the data :-";
    cin >> pos;
    if (pos > n+1)
        cout << "enter valid positon";
    else
        head = insert_at_n(head, data, pos);

    display(head);
    return 0;

}
