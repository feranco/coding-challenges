//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
//design an algorithm to find the maximum profit.
//Note that you cannot sell a stock before you buy one.

#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = numeric_limits<int>::max(), maxGain = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxGain = max(maxGain, price-minPrice);
    }
    return maxGain;
}

int main(void) {
  vector<int> stocks {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
  cout << maxProfit(stocks);
}
