#include <iostream>
using namespace std;

bool isEven(int num)
{
    bool solution = true;
    if (num & 1)
    {
        solution = false;
    }
    return solution;
}

int main()
{
    cout << (isEven(10) ? "Even" : "Odd") << endl;
    cout << (isEven(11) ? "Even" : "Odd") << endl;
    cout << (isEven(17) ? "Even" : "Odd") << endl;
    cout << (isEven(15) ? "Even" : "Odd") << endl;
    cout << (isEven(12) ? "Even" : "Odd") << endl;
    cout << (isEven(22) ? "Even" : "Odd") << endl;
    return 0;
}