#include <iostream>
#include <climits>
using namespace std;

int maxProfit(int *arr, int n) {
    int profit = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int bestBuyDay = arr[i];
        for (int j = 0; j < i; j++)
        {
            bestBuyDay = min(bestBuyDay, arr[j]);
        }
        profit = max(profit, arr[i] - bestBuyDay);
    }
    return profit;
}

int main() {
    int prices[] = {7,6,4,3,1};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int profit = maxProfit(prices, pricesSize);
    cout << "Max Profit: " << profit << endl;
    return 0;
}