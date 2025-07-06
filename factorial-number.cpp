#include <iostream>
using namespace std;

int factorial(int num)
{
    int temp = 1;
    while (num > 1)
    {
        temp *= num;
        num--;
    }
    return temp;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    return 0;
}
