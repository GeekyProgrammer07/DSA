#include <iostream>
using namespace std;

int fastPower(int n, int pow) {
    int ans = 1;
    while (pow > 0)
    {
        if (pow & 1)
        {
            ans *= n;
        }
        n *= n;        
        pow >>= 1;    
    }
    return ans;
}


int main() {
    cout << fastPower(2,5) << endl;
    return 0;
}