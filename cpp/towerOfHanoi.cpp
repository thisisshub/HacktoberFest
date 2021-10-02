#include <bits/stdc++.h>
using namespace std;

void TOH(int n,char from,char to, char aux) {
  if(n == 1) {
    cout<<"Move disk 1 from rod "<<from<<" to rod "<<to<<endl;
    return;
  }
  TOH(n-1,from,aux,to);
  cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
  TOH(n-1,aux,to,from);
}

int main() {
  int n; 
  cin>>n;

  TOH(n,'A','B','C');
  return 0;
}