// Write an efficient function that takes stock_prices and returns the best profit
// I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.

#include <iostream>
#include <cstdlib>

using namespace std;

// worst solution - iterate through all possibly pairs of buys & sells
// runtime O(n^2), space O(1)
void max_profit(int stock_prices[], int size) {
  int max_profit = -INT_MAX, buy_at = -1, sell_at = -1;

  for(int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j < size; j++) {
      if(stock_prices[j] - stock_prices[i] > max_profit) {
        max_profit = stock_prices[j] - stock_prices[i];
        buy_at = i;
        sell_at = j;
      }
    }
  }
  cout << "max profit: " << max_profit << ", buy_at: " << buy_at << ", sell_at: " << sell_at << endl;
}

// better solution - only iterate through array once, track difference with min elt so far
// runtime O(n), space O(1)
void max_profit_2(int stock_prices[], int size) {
  int max_profit = -INT_MAX, min_elt = INT_MAX;

  min_elt = stock_prices[0];
  for(int i = 1; i < size; i++) {
    if(stock_prices[i] - min_elt > max_profit)
      max_profit = stock_prices[i] - min_elt;
    if(stock_prices[i] < min_elt)
      min_elt = stock_prices[i];
  }

  cout << "max profit: " << max_profit << endl;
}

int main() {

  int size = 10;
  int stock_prices[size];
  for(int i = 0; i < size; i++)
    stock_prices[i] = 500 + rand() % 100 - rand() % 50;

  // stocks go down all day - best profit is a negative profit
  // int size = 3;
  // int stock_prices[] = {450, 400, 375};

  for(int i = 0; i < size; i++)
    cout << stock_prices[i] << " ";
  cout << endl;

  max_profit(stock_prices, size);
  max_profit_2(stock_prices, size);
}