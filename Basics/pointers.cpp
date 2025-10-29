#include <iostream>
using namespace std;

void passByValue(int x) {
    x = x + 10;
}

void passByReference(int &x) {
    x = x + 10;
}

int main() {
    int a = 5;
    int* ptr = &a;  // pointer to a
    int* nullPtr = nullptr;  // null pointer

    cout << "Address of a: " << &a << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;

    int val = 100;
    passByValue(val);
    cout << "After passByValue: " << val << endl;

    passByReference(val);
    cout << "After passByReference: " << val << endl;

    int &ref = a;
    ref += 20;
    cout << "\nReference variable updated a to: " << a << endl;

    return 0;
}
