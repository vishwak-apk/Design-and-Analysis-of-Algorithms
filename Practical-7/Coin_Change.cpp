#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int total) {
    vector<int> dp(total + 1, 0);

    // There is 1 way to make total 0:
    // choose no coins.
    dp[0] = 1;

    for (int coin : coins) {
        for (int amount = coin; amount <= total; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[total];
}

int main() {
    int n, total;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter total amount: ";
    cin >> total;

    cout << "Number of ways = " << coinChange(coins, total);

    return 0;
}