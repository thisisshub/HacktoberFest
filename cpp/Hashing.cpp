#include <iostream>
#include <cstdlib>
#include <locale>   
using namespace std;

class Node{
	public:
		string name;
		Node *next; 
};

class Hashing{
	public:
	Node *first;
	Node *array[100];
	
	bool isEmpty(){
		return first==NULL;
	}

	
	int random(){
		return rand() % 300 + 1;
	}
	
	int Address(){
		int Key = random();
		int HashCode = Key % 100;
		
		return HashCode;
	}
	
	
	void insert(string name){
		Node *newnode = new Node();
		newnode->name = name;
		
		int arrayIndex = Address();
			if(array[arrayIndex]==NULL){
				//that index is free to use for a new link list
				array[arrayIndex] = newnode;

			}else{
				Node *temp = array[arrayIndex];
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->next = newnode;
			}	
	}
	
	void print(){
		int i =0;
		while(i<100){
			if(array[i]!=NULL){
				Node *temp = array[i];
				while(temp!=NULL){
					cout<<"index at "<<i<<" "<<temp->name<<endl;
					temp  = temp->next;
				}
			}
			i++;
		}
	}
};
int main(){
	Hashing *object = new Hashing();
	
		object->insert("A");
		object->insert("d");
		object->insert("n");
		object->insert("c");
	object->print();
	


    
	
}
