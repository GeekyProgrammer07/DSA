#include <iostream>
#include <cmath> 
using namespace std;

int binToDec(int binNumber);

int main() {
    int n;
    cout << "Enter the Binary number: ";
    cin >> n;
    
    cout << binToDec(n) << endl;
    return 0;
}

int binToDec(int binNumber) {
    int decimal = 0;
    int power = 0;
    while (binNumber > 0)
    {
        decimal += pow(2, power) * (binNumber % 10);
        power++; 
        binNumber /= 10;
    }
    return decimal;
}
