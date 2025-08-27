#include <iostream>
using namespace std;

bool checkPow2(int n)
{
    if (n & (n - 1))
    {
        return false;
    }
    return true;
}

int main()
{
    cout << (checkPow2(31) ? "true" : "false") << endl;
    return 0;
}