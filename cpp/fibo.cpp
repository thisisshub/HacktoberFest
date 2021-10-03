#include<iostream>

using namespace std;

class fibonacci

{

int k1,k2;

public:

fibonacci()

{

k1 = 0; k2 = 1;

}

void series(int n)

{

int i,next;

cout << k1 << " " << k2 << " " ;

for(i=1; i <= n-2; i++)

{

next = k1 + k2;

cout << next << " " ;

k1 = k2; k2 = next;

}

}

};

int main()

{

fibonacci snehal;

int n;

cout << "FIBONACCI SERIES " << endl ;

cout << "How many numbers do you want ? ";

cin >> n;

snehal.series(n);

}
