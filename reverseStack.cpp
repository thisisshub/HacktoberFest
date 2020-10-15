#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {

    if(input.size()==0 || input.size()==1){
        return ;
    }
    int x= input.top();
    input.pop();
    reverseStack(input , extra);

    while(input.size()!=0){
        int y=input.top();
        extra.push(y);
        input.pop();
    }

    extra.push(x);

    while(!extra.empty()){
        int y=extra.top();
        input.push(y);
        extra.pop();
    }
    return;

}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {

        cout << input.top() << " ";
        input.pop();
    }
}
