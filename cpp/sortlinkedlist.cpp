// Efficient CPP program to sort given list in order
// elements are appearing in an array
#include <bits/stdc++.h>
using namespace std;

// Linked list node
struct Node {
	int data;
	struct Node* next;
};

// function prototype for printing the list
void printList(struct Node*);

// Function to insert a node at the
// beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node -> data = new_data;
	new_node -> next = *head_ref;
	*head_ref = new_node;
}

// function to print the linked list
void printList(struct Node* head)
{
	while (head != NULL) {
		cout << head -> data << " -> ";
		head = head -> next;
	}
}

// Function that sort list in order of apperaing
// elements in an array
void sortlist(struct Node* head)
{
	// Store frequencies of elements in a
	// hash table.
	unordered_map<int, int> hash;
	struct Node* temp = head;
	while (temp) {		
		hash[temp -> data]++;
		temp = temp -> next;
	}

	temp = head;

	// One by one put elements in lis according
	// to their appearance in array
	//for (int i = 0; i < N; i++) {		

		// Update 'frequency' nodes with value
		// equal to arr[i]
	//	int frequency = hash[arr[i]];
	//	while (frequency--) {

			// Modify list data as element
			// appear in an array
		//	temp -> data = arr[i];
		//	temp = temp -> next;
		//}
	//}
}

// Driver Code
int main()
{
	struct Node* head = NULL;
	//int arr[] = { 5, 1, 3, 2, 8 };
	//int N = sizeof(arr) / sizeof(arr[0]);

	// creating the linked list
	push(&head, 3);
	push(&head, 2); 
	push(&head, 5);
	push(&head, 8);
	push(&head, 5);
	push(&head, 2);
	push(&head, 1);

	// Function call to sort the list in order
	// elements are apperaing in an array
	sortlist( head);

	// print the modified linked list
	cout << "Sorted List:" << endl;
	printList(head);
	return 0;
}


