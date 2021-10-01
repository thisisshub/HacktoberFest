bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    if (strlen(input1) != strlen(input2))
    {
        return false;
    }
    else
    {
        int cnt1[256]={0};
        int cnt2[256]={0};
        int i;
        for (i=0; input1[i] && input2[i]; i++)
        {
            cnt1[input1[i]]++;
            cnt2[input2[i]]++;
        }
        for (i=0; i<256; i++)
        {
            if (cnt1[i] != cnt2[i])
                return false;
        }
        return true;
    }
}
#include <iostream>
#include <cstring>
using namespace std;


int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}
