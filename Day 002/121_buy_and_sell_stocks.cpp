#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void maxProfit(vector<int>& prices) {
    vector<int> bestBuy(prices.size());
    bestBuy[0] = INT_MAX;
    for (int i = 1; i < prices.size(); i++) {
        bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
    }
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
        int currentProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currentProfit);
    }
    cout << "Maximum Profit: " << maxProfit << endl;
}
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    maxProfit(prices);
}

// buy and sell stocks problem solution using arrays
// #include <iostream>
// #include <climits>
// using namespace std;
// void maxProfit(int prices[], int n) {
//     int bestBuy[100000];
//     bestBuy[0] = INT_MAX;
//     for (int i = 1; i < n; i++) {
//         bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
//     }
//     int max_Profit = 0;
//     for (int i = 0; i < n; i++) {
//         max_Profit = max(max_Profit, prices[i] - bestBuy[i]);
//     }
//     cout << "Maximum Profit: " << max_Profit << endl;
// }
// int main() {
//     int prices[] = {7, 1, 5, 3, 6, 4};
//     int n = sizeof(prices) / sizeof(prices[0]);
//     maxProfit(prices, n);
//     return 0;
// }