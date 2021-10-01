#include <iostream>
using namespace std;

class Data
{
private:
    int a, b, c; // Declaring private variables.
public:
    int d, e;
    void setData(int a1, int b1, int c1)
    {
        a = a1;
        b = b1;
        c = c1;
        d = a + b;
        e = a + b + c;
    }
    void getData()
    {
        cout << "Value of a: " << a << endl;
        cout << "Value of b: " << b << endl;
        cout << "Value of c: " << c << endl;
        cout << "Value of d(a+b): " << d << endl;
        cout << "Value of e(d+c): " << e << endl;
    }
};

int main()
{
    int a, b, c;
    Data d1; // Declaring Object
    d1.setData(2, 3, 4);
    d1.getData();
    return 0;
}