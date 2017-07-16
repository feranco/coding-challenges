#include <array>
#include <iostream>

using std::array;

template <std::size_t SIZE>
int maxProfit (const array<int,SIZE>& stock) {
  int min_stock = stock[0], max_profit = 0;
  for (auto& s : stock) {
    int profit = s - min_stock;
    if (profit > max_profit) max_profit = profit;
    if (s < min_stock) min_stock = s;
  }
  return max_profit;
}

int main(void) {
  array<int, 10> stocks {{310, 315, 275, 295, 260, 270, 290, 230, 255, 250}};
  std::cout << maxProfit(stocks);
}
