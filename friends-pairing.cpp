#include <iostream>
using namespace std;

int ways(int n) {
    if (n == 1 || n == 2)
    {
        return n;
    }
    
    return ways(n-1) + (n-1) * ways(n-2); //suppose a friends pairs up so hey has n-1 choices to pair up
}

int main() {
    cout << ways(4) << endl;
    return 0;
}