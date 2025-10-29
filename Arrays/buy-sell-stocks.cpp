#include <iostream>
#include <climits>
using namespace std;

int maxProfit(int *prices, int n)
{
    int bestBuy[n];
    bestBuy[0] = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        int currentProfit = prices[i] - bestBuy[i];
        maxProfit  =  max(currentProfit, maxProfit);
    }
    return maxProfit;
}

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int profit = maxProfit(prices, pricesSize);
    cout << "Max Profit: " << profit << endl;
    return 0;
}

// int maxProfit(int *arr, int n) {
//     int profit = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int bestBuyDay = arr[i];
//         for (int j = 0; j < i; j++)
//         {
//             bestBuyDay = min(bestBuyDay, arr[j]);
//         }
//         profit = max(profit, arr[i] - bestBuyDay);
//     }
//     return profit;
// }