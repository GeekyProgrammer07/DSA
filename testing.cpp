#include <iostream>
using namespace std;

void changeA(int* a){
    *a = 30;
}

int main()
{
    // int a;
    // int *aPtr = &a;
    // int **pptr = &aPtr;
    // cout << aPtr << endl;
    // cout << &aPtr << endl;
    // cout << pptr << endl;
    // a = 20;

    // cout << "value of a: " << *pptr << endl;

    //NULL pointer
    // int a;
    // int* something = NULL;
    // something = &a;
    // *something = 20;
    // cout << *something << endl;

    int a = 10;
    cout << "Before Update: " << a << endl;

    changeA(&a);

    cout << "After Update: " << a << endl;

    return 0;
}