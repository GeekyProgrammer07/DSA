#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter the number: ";
    cin >> n;
    int reversed_number = 0;
    while (n > 0) {
        reversed_number = (reversed_number * 10) + (n % 10);
        n /= 10; 
    }
    cout << "Reversed Number: " << reversed_number << endl;
    return 0;
}