#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n) {
	int lowest=arr[0],highest=arr[0],ans=arr[0];
	for (int i = 1; i < n; i++) {
		int tmp=lowest;
		lowest=min({lowest*arr[i],highest*arr[i],arr[i]});
		highest=max({highest*arr[i],tmp*arr[i],arr[i]});
        ans = max({ans, lowest, highest});
    }
	return ans;
}