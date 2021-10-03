//compile time or static
// depends parameter passed
//function overloading //same name

#include <iostream>
using namespace std;

class add
{
public:
    int sum(int n1, int n2)
    {
        cout << "TWO :";
        return n1 + n2;
    }
    int sum(int n1, int n2, int n3)
    {
        cout << "THREE :";
        return n1 + n2 + n3;
    }
};

int main()
{
    add s1;
    cout << s1.sum(10, 20);
    cout << endl;
    cout << s1.sum(10, 20, 30);

    return 0;
}