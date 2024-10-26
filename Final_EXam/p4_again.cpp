#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;    // Maximum number of elements in the list
const int MAX_T = 1005;    // Maximum target sum (1000 - k)

bool dp[MAX_N][MAX_T];    // DP table to store results

bool canFormTarget(int n, int target, int num[]) {
    // Initialize the DP table for subset sum problem
    memset(dp, false, sizeof(dp));

    // Base case: a subset with sum 0 is always possible (empty subset)
    dp[0][0] = true;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            // Either we take the current number, or we don't
            dp[i][j] = dp[i-1][j];  // Not taking current number
            if (j >= num[i-1]) {
                dp[i][j] |= dp[i-1][j - num[i-1]];  // Taking current number
            }
        }
    }

    return dp[n][target];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int num[n];

        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        // Calculate the target we need to reach: 1000 - k
        int target = 1000 - k;

        // If the target is negative, it's impossible to reach it
        if (target < 0) {
            cout << "NO" << endl;
        } else {
            // Check if it's possible to form the target sum
            if (canFormTarget(n, target, num)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

