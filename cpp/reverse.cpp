#include <algorithm>
void reverseEachWord(char input[]) {
    // Write your code here
    int pos=-1;
    
    for (int i=0; i<=strlen(input); i++)
    {
        if(input[i]==' ' || input[i]== '\0')
        {
            reverse(input+pos+1, input+i);
            pos=i;
        }
    }
}
#include <iostream>
#include <cstring>
using namespace std;

// #include "solution.h"

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}
