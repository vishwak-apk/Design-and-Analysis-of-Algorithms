
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 999999

int n;
int cost[10][10];
int dp[10][1 << 10];

int tsp(int city, int mask) {

    // All cities visited
    if (mask == (1 << n) - 1)
        return cost[city][0];

    if (dp[city][mask] != -1)
        return dp[city][mask];

    int ans = INF;

    for (int i = 0; i < n; i++) {

        // Check if city is not visited
        if ((mask & (1 << i)) == 0) {

            int newCost = cost[city][i] +
                          tsp(i, mask | (1 << i));

            ans = min(ans, newCost);
        }
    }

    return dp[city][mask] = ans;
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + 10 * (1 << 10), -1);

    int answer = tsp(0, 1);

    cout << "Minimum travelling cost: " << answer << endl;

    return 0;
}
