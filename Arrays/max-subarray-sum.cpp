#include <iostream>
#include <climits>
using namespace std;

// Kadane's Algo
int maxSubarraySum(int *arr, int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {-5, -3, -6, -5, -4, -2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int max = maxSubarraySum(arr, arrSize);
    cout << "Max: " << max << endl;
    return 0;
}

// Brute Force
//  int maxSubarraySum(int *arr, int n)
//  {
//      int max = INT_MIN;
//      for (int start = 0; start < n; start++)
//      {
//          for (int end = start; end < n; end++)
//          {
//              int sum = 0;
//              for (int i = start; i <= end; i++)
//              {
//                  sum += arr[i];
//              }
//              max = std::max(max, sum);
//          }
//      }
//      return max;
//  }

// Bit Optimized
// int maxSubarraySum(int *arr, int n)
// {
//     int max = INT_MIN;
//     for (int start = 0; start < n; start++)
//     {
//         int currentSum = 0;
//         for (int end = start; end < n; end++)
//         {
//             currentSum += arr[end];
//             max = std::max(max, currentSum);
//         }
//     }
//     return max;
// }
