/*
Overview:
- Finds the maximum profit from one buy/sell transaction.
Approach:
- Track the minimum price so far and update max profit.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int max_profit_one_transaction(const int prices[], int n) {
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else {
            int profit = prices[i] - min_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

int main(void) {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = (int)(sizeof(prices) / sizeof(prices[0]));

    printf("Max profit = %d\n", max_profit_one_transaction(prices, n));
    return 0;
}
