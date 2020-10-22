#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *left, *right;
};

struct Node *insert(int aa) {
	struct Node *a = new Node;
	a->value = aa;
	a->left = a->right = NULL;
	return a;
}

void traverse(Node *a) {
	if (a == NULL)
		return;
	cout << a->value;
	if (a->left != NULL) {
		traverse(a->left);
		cout << a->value;
	}
	if (a->right != NULL) {
		traverse(a->right);
		cout << a->value;
	}
}

int main() {

	struct Node *a = insert(1);
	a->left = insert(5);
	a->left->left = insert(4);
	a->left->left->right = insert(3);
	a->left->left->left = insert(2);

	traverse(a);
}