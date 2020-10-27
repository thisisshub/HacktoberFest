#include "iostream"
using namespace std;

struct node{
    int data;
    struct node *leftData, *rightData;
};

node *nodeObj;

node *tree(node *nodeObj, int data){
    if (nodeObj == NULL){
        node *temp;
        temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->leftData = temp->rightData = NULL;
        return temp;
    }
    
    if (data < (nodeObj->data))
        nodeObj->leftData = tree(nodeObj->leftData, data);
    
    else if (data > nodeObj -> data)
        nodeObj->rightData = tree(nodeObj->rightData, data);
    
    return nodeObj;
}

node *searchNode(node *nodeObj, int data){
    if (nodeObj == NULL)
        printf("\nElement Not Found As Tree Is Empty");
    
    else if (data < nodeObj->data)
        nodeObj->leftData = searchNode(nodeObj->leftData, data);
    
    else if (data > nodeObj -> data)
        nodeObj->rightData = searchNode(nodeObj->rightData, data);
    
    else
        cout << endl << nodeObj->data << " Element Found!";
    
    return nodeObj;
}

void displayInOrder(node *nodeObj){
    if (nodeObj != NULL){
        displayInOrder(nodeObj->leftData);
        cout << nodeObj->data << "\t";
        displayInOrder(nodeObj->rightData);
    }
}

void displayPreOrder(node *nodeObj){
    if (nodeObj != NULL){
        cout << nodeObj->data << "\t";
        displayPreOrder(nodeObj->leftData);
        displayPreOrder(nodeObj->rightData);
    }
}

void displayPostOrder(node *nodeObj){
    if (nodeObj != NULL){
        displayPostOrder(nodeObj->leftData);
        displayPostOrder(nodeObj->rightData);
        cout << nodeObj->data << "\t";
    }
}

node *findMin(node *nodeObj){
    if (nodeObj == NULL)
        return NULL;
    
    if (nodeObj->leftData)
        return findMin(nodeObj->leftData);
    
    else
        return nodeObj;
}

node *deleteNode(node *nodeObj, int data){
    node *temp;
    
    if (nodeObj == NULL)
        cout << "\nElement Not Found As Tree Is Empty";
    
    else if (data < nodeObj->data)
        nodeObj->leftData = deleteNode(nodeObj->leftData, data);
    
    else if (data > nodeObj->data)
        nodeObj->rightData = deleteNode(nodeObj->rightData, data);
    
    else{
        if (nodeObj->rightData && nodeObj->leftData){
            temp = findMin(nodeObj->rightData);
            nodeObj->data = temp->data;
            nodeObj->rightData = deleteNode(nodeObj->rightData, temp->data);
        }
        
        else{
            temp = nodeObj;
            if (nodeObj->leftData == NULL)
                nodeObj = nodeObj->rightData;
            else if (nodeObj->rightData == NULL)
                nodeObj = nodeObj->leftData;
            free(temp);
        }
    }
    return nodeObj;
}

int main(){
    int data, ch, nodeCount;
    node *root = NULL;
    while (true){
        cout << "\n1.Insert Element";
        cout << "\n2.Search Element";
        cout << "\n3.Delete Element";
        cout << "\n4.Display Inorder";
        cout << "\n5.Display Preorder";
        cout << "\n6.Display Postorder";
        cout << "\n7.Exit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        if (ch== 1){
            cout << "\nEnter No Of Nodes : ";
            cin >> nodeCount;
            for (int i=0; i<nodeCount; i++){
                cout << "Enter Node Value N[" << i << "]: ";
                cin >> data;
                root = tree(root, data);
            }
        }

        else if (ch== 2){
            cout << "\nEnter The Element To Search: ";
            cin >> data;
            root = searchNode(root, data);
        }
        
        else if (ch== 3){
            cout << "\nEnter The Element To Delete: ";
            cin >> data;
            root = deleteNode(root, data);
        }
        
        else if (ch== 4)
            displayInOrder(root);
        
        else if (ch== 5)
            displayPreOrder(root);
        
        else if (ch== 6)
            displayPostOrder(root);
        
        else if (ch== 7)
            exit(0);
        
        else
            cout << "Incorrect Choice, Please Try Again";
    }
}
