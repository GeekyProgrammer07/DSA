#include <iostream>
using namespace std;

int main() {
    int n;
    while(true) {
        cout << "Enter the number: ";
        cin >> n;
        if(n % 10  == 0) {
            cout << "You entered a multiple of 10" << endl;
            break;
        } else {
            continue;
        }
    }
    return 0;
}