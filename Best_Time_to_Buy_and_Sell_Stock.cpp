#include <bits/stdc++.h> 

int maximumProfit(std::vector<int> &prices){
    int globalMax = 0;
    int n = prices.size();
    std::vector<int> cummax(n+1, 0);
    cummax[n] = prices[n-1];

    for(int i = n-1; i >= 0; i--)
    {
        cummax[i] = std::max(cummax[i+1], prices[i]); 
    }
    
    for (int i = 0; i < n - 1; i++) {
        int nextMax = cummax[i+1];
        int tempAns = nextMax - prices[i];
        globalMax = std::max(globalMax, tempAns);
    }
    
    return globalMax;
}
