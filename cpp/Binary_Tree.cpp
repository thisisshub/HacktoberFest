#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printIn(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printIn(root->left);
    cout << root->data << ",";
    printIn(root->right);
}

void printPre(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ",";
    printPre(root->left);
    printPre(root->right);
}

void printPost(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout << root->data << ",";
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

void printkthLevel(node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout << root->data << " ";
        return;
    }
    else{
        printkthLevel(root->left,k-1);
        printkthLevel(root->right,k-1);
    }

}

void printAlllevels(node* root){
    int h = height(root);
    for(int i=0;i<h ;i++){
        printkthLevel(root,i);
        cout << endl;
    }
}

//TC = O(n)
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << f->data << " ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

int nodeCount(node* root){
    if(root == NULL){
        return 0;
    }
    return nodeCount(root->left)+nodeCount(root->right)+1;
}

int sumofNodes(node* root){
    if(root == NULL){
        return 0;
    }
    return sumofNodes(root->left)+sumofNodes(root->right)+root->data;
}


//O(n2) complexity
int diameterTree(node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2;
    int op2 = diameterTree(root->left);
    int op3 = diameterTree(root->right);
    return max(op1,max(op2,op3));
}

class Pair{
    public:
        int diameter;
        int height;
};
//O(N) Complexity
Pair diameterOptimised(node* root){
    Pair p;
    if(root == NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair leftPair = diameterOptimised(root->left);
    Pair rightPair = diameterOptimised(root->right);

    p.diameter = max(leftPair.height+rightPair.height, max(leftPair.diameter,rightPair.diameter));
    p.height = max(leftPair.height,rightPair.height) + 1; 
    return p;
}

int sumReplacement(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int temp = root->data;
    root->data = sumReplacement(root->left) + sumReplacement(root->right);
    return root->data + temp;
}
//Unoptimised
bool heightBalanced(node* root){
    if(root == NULL){
        return true;
    }
    //Otherwise
    int h1 = height(root->left);
    int h2 = height(root->right);
    if(abs(h1-h2) <= 1 && heightBalanced(root->left) && heightBalanced(root->right)){
        return true;
    }
    else{
        return false;
    }
}

//Optimised Balanced Tree
class HBPair{
    public:
        int height;
        int balanced;
};
//bottom to top approach - postorder
HBPair heightBalancedOptimised(node* root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balanced = true;
        return p;
    }
    //Recursive Case
    HBPair left = heightBalancedOptimised(root->left);
    HBPair right = heightBalancedOptimised(root->right);

    p.height = max(left.height , right.height) + 1;
    if(abs(left.height-right.height) <= 1 and left.balanced and right.balanced){
        p.balanced = true;
    }
    else{
        p.balanced = false;
    }
    return p;
}

node* buildBalancedTree(int *arr, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s + e)/2;
    node* root = new node(arr[mid]);
    root->left = buildBalancedTree(arr,s,mid-1);
    root->right = buildBalancedTree(arr,mid+1,e);
    return root;
}

//Algo for building a tree from preorder+inorder
//1. iterate preorder and pick one item, create a node
//2. search that item's index in inorder, let the index is i.
//3. make a recursive call on arr(0,i-1) and arr(i+1,e) and attach to the left and right subtree of previous node.

node* createtreefromTrav(int *in, int *pre, int s, int e){
    static int i =0;
    //Base case
    if(s>e){
        return NULL;
    }
    //recursive case
    node* root = new node(pre[i]);
    int index = -1;
    for(int j =s ; j<=e ; j++){
        if(pre[i] == in[j]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createtreefromTrav(in,pre,s,index-1);
    root->right = createtreefromTrav(in,pre,index+1,e);
    return root;
}

void rightview(node* root, int level, int &maxlevel){
    if(root == NULL){
        return;
    }
    if(level > maxlevel){
        //found new level so printing it's data
        cout << root->data << ",";
        maxlevel = level;
    }
    rightview(root->right, level+1, maxlevel);
    rightview(root->left,level+1, maxlevel);
}

int printAtDistanceK(node* root, node* target, int k){
    if(root == NULL){
        return -1;
    }
    //reach the target node
    if(root == target){
        printkthLevel(target,k);
        return 0;
    }
    //ancestor
    int DL = printAtDistanceK(root->left,target,k);
    if(DL != -1){
        //Again 2 cases
        //Ancestor itself or you need to go to right subtree
        if(DL +1 == k){
            cout << root->data << " ";
        }
        else{
            printkthLevel(root->right,k-2-DL);
        }
        return 1+DL;
    }
    int DR = printAtDistanceK(root->right,target,k);
    if(DR != -1){
        if(DR+1 == k){
            cout << root->data << " ";
        }
        else{
            printkthLevel(root->left,k-2-DR);
        }
        return 1+DR;
    }
    //node was not present in left and right subtree of given node
    return -1;
}

//assuming both a and b is present in tree , all keys are unique
node* lca(node* root, int a,int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a or root->data == b){
        return root;
    }
    //searching in left and right subtrees
    node* leftans = lca(root->left,a,b);
    node* rightans = lca(root->right,a,b);
    if(leftans != NULL and rightans != NULL){
        return root;
    }
    else if(leftans!=NULL){
        return leftans;
    }
    return rightans;
}

node* deletion(node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return NULL;
    }
    
    root->left = deletion(root->left,key);
    root->right = deletion(root->right,key);
    return root;
}

int main()
{
    //Sample Input -> 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    
    node *root = buildTree();

    // printPre(root);
    // cout << endl;
    // printIn(root);
    // cout << endl;
    // printPost(root);
    // cout << endl;
    // cout << height(root);
    // cout << endl;
    // printAlllevels(root);
    bfs(root);
    // cout << nodeCount(root) << "\n";
    // cout << sumofNodes(root) << "\n";

    // cout << diameterTree(root) << endl;
    // Pair p = diameterOptimised(root);
    // cout << "Daimeter : " << p.diameter << endl;
    // cout << "Height : "<< p.height << endl;

    // sumReplacement(root);
    // bfs(root);
    // HBPair p = heightBalancedOptimised(root);

    // if(p.balanced){
    //     cout << "TREE IS BALANCED!" << endl;
    // }
    // else{
    //     cout << "TREE UNBALANCED!" << endl;
    // }
    // int arr[7] = {1,2,3,4,5,6,7};
    // node* newroot = buildBalancedTree(arr,0,6);
    // bfs(newroot);
    // int pre[9] = {8,10,1,6,9,7,3,14,13};
    // int in[9] = {1,10,9,6,7,8,3,13,14};
    // node* newroot = createtreefromTrav(in,pre,0,8);
    // bfs(newroot);
    // int maxlevel = -1;
    // rightview(root,0,maxlevel);

    // node* target = root->left; 
    // int k=2;
    // printAtDistanceK(root,target,k);

    // node* ans = lca(root,10,9);
    // cout << ans->data << endl;

    root = deletion(root,6);
    bfs(root);

    return 0;
}
