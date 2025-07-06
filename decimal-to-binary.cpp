#include <iostream>
#include <cmath>
using namespace std;

int decToBin(int num)
{
    int power = 0;
    int reversedBin = 0;
    while (num > 0)
    {
        reversedBin += (num % 2) * pow(10, power);
        power++;
        num /= 2;
    }
    return reversedBin;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << decToBin(n) << endl;
    return 0;
}
