#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int trap(int *height, int n)
{
    int leftMax[n], rightMax[n];
    leftMax[0] = INT_MIN, rightMax[n - 1] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        rightMax[n - i - 1] = max(rightMax[n - i], height[n - i]);
    }

    int trapped_water = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (height[i] < leftMax[i] && height[i] < rightMax[i])
        {
            trapped_water += min(leftMax[i], rightMax[i]) - height[i];
        }
    }
    return trapped_water;
}

int main()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int trapedWater = trap(height, heightSize);
    cout << "Trapped Water: " << trapedWater << endl;
    return 0;
}