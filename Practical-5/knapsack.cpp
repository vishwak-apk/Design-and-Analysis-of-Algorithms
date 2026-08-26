#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // dp[i][w] = maximum value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // Don't take the current item
            dp[i][w] = dp[i - 1][w];

            // Take the current item if it fits
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]
                );
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value = "
         << knapsack(W, wt, val, n) << endl;

    return 0;
}
