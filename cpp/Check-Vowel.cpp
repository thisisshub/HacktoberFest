#include <iostream>
using namespace std;
int main(){
    char ch;
    cin>>ch;
    switch(ch):{
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        cout<<"Upper Case Vowel";
        break;
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        cout<<"Lower case Vowel";
        break;
        default:
        cout<<"Not a Vowel"
    }
}
