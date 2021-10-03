#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define ll long long
#define f(i,j,k) for(i=j;i<k;i++)
#define test_case ll t; scanf("%lld",&t); while(t--)
#define scanl(a,n) ll a[n]; for(i=0;i<n;i++) scanf("%lld",&a[i])
#define printl(a,n) for(i=0;i<n;i++) printf("%lld ",a[i])
#define input(n) ll n; scanf("%lld",&n)
#define inpstr(a,n) ll n; scanf("%lld",&n);getchar();char a[n+1];gets(a)

//Start here
class node{
public:
    int val;
    node* ind;
    node(ll i){
        val=i;
        ind=NULL;
    }
};

void insertVal(ll i,node* &start){
    node* n=new node(i);
    if(start==NULL){
        start=n;
        return 0;
    }
    node* test=start;
    while(test->ind!=NULL){
        test=test->ind;
    }
    test->ind=n;

}
void printList(node *start){
    while(start->ind!=NULL){
        cout<<start->val<<"->";
        start=start->ind;
    }
    cout<<start->val<<endl;
}
void insertMid(node *start,ll i,ll n){
    node *test=start;
    while(n>1){
        test=test->ind;
        n--;
    }
    node *x=new node(i);
    node* temp=test->ind;
    test->ind=x;
    x->ind=temp;

}
void delMid(node* &start,ll n){
    node *test=start;
    ll lenAvil=0;
    if(n==0){
        node* test=start->ind;
        start=test;
        return 0;
    }
    if(n==1){
        node* next=(test->ind);
        (test->ind)->ind=next->ind;
    }
    while(n>1){
        lenAvil++;
        test=test->ind;
        n--;
    }
    node* next=(test->ind);
    test->ind=next->ind;

}
void swapVal(node * start,ll i,ll j){

    node *check=start;
    while(i>1){
        check=check->ind;
        i--;
    }
    node *ind1=check;
    check=start;
    while(j>1){
        check=check->ind;
        j--;
    }
    node* ind2=check;
    node *toswap=ind1->ind;
    node *next1=ind1->ind->ind;
    node *next2=ind2->ind->ind;
    //second to 1st
    ind1->ind=ind2->ind;
    ind1->ind->ind=next1;
    // 1st to second
    ind2->ind=toswap;
    toswap->ind=next2;

}
void insertHead(ll i,node* & start){
    node* n=new node(i);
    n->ind=head;
    head=n;
}
bool search(ll i, node* start){
    while(start->ind!=NULL){
        if(start->val==i) return 1;
        start=start->ind;
    }
    return 0;
}
void deleteFirst(node*&start){
    start=start->ind;
}
void deletelast(node* start){
    while(start->ind->ind!=NULL) start=start->ind;
    start->ind=NULL:
}
bool count(ll i, node* start){
    ll cnt=0;
    while(start->ind!=NULL){
        if(start->val==i) cnt++;
        start=start->ind;
    }
    return cnt;
}
node* findLast(ll i, node* start){
    node* n=NULL;
    while(start->ind!=NULL){
        if(start->val==i) n=start;
        start=start->ind;
    }
    return n;
}



int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll i,j,k,n;
    node *start=NULL;
    
    f(i,1,11) insertVal(i,start);
    
    printList(start);
    cin>>i>>j;
    swapVal(start,3,5);
    printList(start);
    
    

    return 0;
}