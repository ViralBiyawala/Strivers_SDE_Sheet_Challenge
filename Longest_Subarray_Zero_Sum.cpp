#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr) {
    int n = arr.size();
    unordered_map<int, int> prefixSum;
    int maxLength = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        if (currSum == 0)
            maxLength = i + 1;
        if (prefixSum.find(currSum) != prefixSum.end())
            maxLength = max(maxLength, i - prefixSum[currSum]);
        else
            prefixSum[currSum] = i;
    }

    return maxLength;
}
