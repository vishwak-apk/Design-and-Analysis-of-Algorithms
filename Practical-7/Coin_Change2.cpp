#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] = minimum coins needed to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // 0 coins are needed to make amount 0
    dp[0] = 0;

    // Calculate minimum coins for each amount
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {

            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == amount + 1)
        cout << "Amount cannot be made using given coins.";
    else
        cout << "Minimum number of coins = " << dp[amount];

    return 0;
}