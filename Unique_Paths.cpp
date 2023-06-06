#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (m == 1 || n == 1)
        return 1;

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    // Base cases
    dp[0][0] = 0;
    for (int i = 1; i < m; i++)
        dp[i][0] = 1;
    for (int j = 1; j < n; j++)
        dp[0][j] = 1;

    // Fill the dp array
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}
