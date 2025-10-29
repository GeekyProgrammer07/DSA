#include <iostream>
using namespace std;

int sumSecondRow(int (*mat)[3], int row, int column)
{
    int sum = 0;
    for (int i = 0; i < column; i++)
    {
        sum += *(*(mat + 1) + i);
    }
    return sum;
}

int main()
{
    int nums[3][3] = {{1, 4, 9},
                      {11, 4, 3},
                      {2, 2, 3}};

    int sum = sumSecondRow(nums, 3, 3);
    cout << "Sum of second row: " << sum << endl;
    return 0;
}