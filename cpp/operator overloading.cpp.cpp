#include<iostream>
using namespace std;
class test 
{
    int a,b;
    public:
    test(int x,int y)
    {
        a=x;
        b=y;
    }
    void operator ++()
    {
        a=++a;
        b=++b;
    }
    void operator --()
    {
        a=--a;
        b=--b;
    }
    void display()
    {
        cout<<"value of a is "<<a<<endl<<"value of b is "<<b<<endl;
    }
};
int main()
{
    test t(10,15);
    ++t;
    t.display();
    --t;
    t.display();
    return 0;
}



