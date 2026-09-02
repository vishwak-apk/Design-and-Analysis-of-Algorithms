#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    // DP table
    int dp[n + 1][n + 1];

    // Cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // length = number of matrices in the chain
    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications = "
         << dp[1][n] << endl;

    return 0;
}