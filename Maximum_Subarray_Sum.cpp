#include <bits/stdc++.h>

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = 0;
    long long currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }    
    return maxSum;
}