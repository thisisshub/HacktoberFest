#include "../libraries/mixin.h"
#define RED true
#define BLACK false
#define HEAD true
#define CHILD false
#define RIGHT 1
#define LEFT  2


struct Node
{
    lld low = -1,hi = -1;
    lld endPoint = -1;
    Node *left = nullptr,*right = nullptr;
    bool color = BLACK;
} typedef n;


void _copy(n &node,n &blueprint)
{
    node.low = blueprint.low;
    node.hi = blueprint.hi;
    node.left = blueprint.left;
    node.right = blueprint.right;
    node.color = blueprint.color;
}

void swapColor(n &node)
{
    if(node.left)
    {
        node.left->color = BLACK;
    }
    if(node.right)
    {
        node.right->color = BLACK;
    }
}

n& _init(lld low = 0,lld hi = INT_MAX)
{
    n *node = new n();
    node->low = low;
    node->hi = INT_MAX;
    return *node;
}

n& rotateLeft(n &nod)  // child node
{
    n *node = new n();
    _copy(*node,nod);

    n *Head = node->right, // new head
       *Left = Head->left; // new node.left right node
    node->right = Left;
    Head->left =  node;
    // color
    Head->color = nod.color;
    node->color = RED;
    return *Head;
}

n& rotateRight(n &nod)
{
    n *node = new n();
    _copy(*node,nod);

    n *Head = node->left, // new head
       *LeftR = node->left->right;
    node->left = LeftR;
    Head->right = node;
    // color

    Head->color = nod.color;
    node->color = RED;

    return *Head;
}

bool isRed(n *node)
{
    if(node)
    {
        return node->color;
    }
    else
        return false;
}


void _insert(n &root,lld low,lld hi)
{
    if(&root == nullptr || (root.low == val && root.hi == hi))
        return;
    if(root.low == -1 || root.hi == -1) // head
    {
        root.low = low;
        root.hi = hi;
        return ;

    }
    if(root.low > low)
    {
        if(root.left == nullptr)
        {
            n *node = new n();
            node->low = low;
            node->hi = hi;
            root.left = node;
            node->color = RED;
        }
        else
            _insert(*root.left,val);
    }
    if(root.low < low)
    {
        if(root.right == nullptr)
        {
            n *node = new n();
            node->low = low;
            node->hi = hi;
            root.right = node;
            node->color = RED;
        }
        else
            _insert(*root.right,val);
    }

    if(!isRed(root.left) && isRed(root.right))
    {
        root = rotateLeft(root);
    }
    if(isRed(root.left) && isRed(root.left->left))
    {
        root = rotateRight(root);
    }
    if(isRed(root.left) && isRed(root.right))
    {
        swapColor(root);
    }
}

bool success(n &node)
{


    n    *Left = node.left,
          *Right = node.right,
           *RL = node.right->left;

    if(Right == nullptr)
    {

        if(Left == nullptr)
            return false;
        node.low = Left->low;
        node.hi = Left->hi;

        return success(*Left);
    }
    else
    {
        if(RL == nullptr)
        {

            node.low = Right->low;
            node.hi = Right->hi;
            node.right = Right->right;
            return true;
        }
        else
        {

            node.low = Right->low;
            node.hi = Right->hi;
            return success(*RL);
        }
    }
}

bool _delete(n &root,lld val)
{
    cout<<1;
    if(&root == nullptr || root.val == -1)
        return false;

    if(root.val == val)
    {
        return success(root);
    }
    else if(root.val > val)
    {
        if(root.left)
        {
            if(root.left->val == val)
            {
                return success(*root.left);
            }
            else
                return _delete(*root.left,low,hi);
        }
        else
            return false;
    }
    else if(root.val < val)
    {
        if(root.right)
        {
            if(root.right->val == val)
            {
                return success(*root.right);
            }
            else
                return _delete(*root.right,low,hi);
        }
        else
            return false;
    }
}

int main()
{
    n root;
    int num;
    cin>>num;
    srand(time(NULL));
    for(int i = 0 ; i < num ; i++)
    {
        lld t = rand()%100;
        cout<<t<<" ";
        _insert(root,t);
    }
    RESULT
    printTree(root," ",0);
//    ENDLINE
//    printTree(root," ",1);
    RESULT
    cin>>num;
    _delete(root,num);
//    cout<<(_get(root,num,CHILD)).val;
    RESULT
    printTree(root," ",0);
}



int main()
{


}
