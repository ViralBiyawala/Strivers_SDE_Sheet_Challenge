#include <vector>
#include <algorithm>

std::vector<int> subsetSum(const std::vector<int>& num) {
    int totalSum = 0;
    for (int n : num) {
        totalSum += n;
    }

    int n = num.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(totalSum + 1, false));

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the dynamic programming table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= num[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - num[i - 1]];
            }
        }
    }

    std::vector<int> res;
    res.push_back(0);
    for (int j = 1; j <= totalSum; j++) {
        if (dp[n][j]) {
            res.push_back(j);
        }
    }

    return res;
}
