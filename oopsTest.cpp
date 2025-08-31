#include <iostream>
using namespace std;

class Parent
{
public:
    static int x;
    void greet()
    {
        cout << "Hey there from parent" << endl;
    }
};

class Child : public Parent
{
public:
    void greet()
    {
        cout << "Hey from child class" << endl;
    }
};

int Parent::x = 0;

int main()
{
    Child c1;
    Child c2;
    cout << c1.x++ << endl;
    cout << c2.x << endl;
    return 0;
}