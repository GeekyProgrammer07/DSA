#include <iostream>
using namespace std;

int getIthBit(int number, int pos)
{
    int bitMask = 1 << pos;
    if (bitMask & number)
    {
        return 1;
    }
    return 0;
}

int setIthBit(int *number, int pos)
{
    int bitMask = 1 << pos;
    *number = *number | bitMask;
    return *number;
}

int clearIthBit(int *number, int pos)
{
    int bitMask = ~(1 << pos);
    *number = *number & bitMask;
    return *number;
}

int main()
{
    cout << getIthBit(7, 5) << endl;
    int a = 6;
    cout << setIthBit(&a, 3) << endl;
    a = 6;
    cout << clearIthBit(&a, 1) << endl;

    return 0;
}