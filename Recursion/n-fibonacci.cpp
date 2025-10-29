#include <iostream>
using namespace std;

int nthFibonacci(int n) {
    if (n == 1 || n == 0)
    {
        return n;
    }
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int main() {
    cout << "Nth Fibo: " <<  nthFibonacci(6) << endl;
    return 0;
}