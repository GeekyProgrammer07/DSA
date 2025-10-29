#include <iostream>
using namespace std;

int countSetBit(int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num & 1)
        {
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int main()
{
    cout << countSetBit(4) << endl;
    cout << countSetBit(10) << endl;
    cout << countSetBit(7) << endl;
    return 0;
}