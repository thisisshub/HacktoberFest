#include<iostream>
using namespace std;

int main()
{
    int n=0, a=0, b=0;
    cin >> n;
    b = n;
    while(n > 0){
        int last = n % 10;
        a += last * last * last;
        n = n / 10;
    }

    if(a == b){
        cout << "yes, it is an armstrong number";
    }

    else{
        cout << "no, it is not";
    }

    return 0;
}
