#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (n <= 1) {
        cout << n << " is not a prime number" << endl;
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << n << " is not a prime number" << endl;
            return 0;
        }
    }

    cout << n << " is a prime number" << endl;
    return 0;
}