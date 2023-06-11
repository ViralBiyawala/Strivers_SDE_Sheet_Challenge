#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> smalllarge;
    sort(arr.begin(), arr.end());
    smalllarge.push_back(arr[k-1]);
    smalllarge.push_back(arr[n-k]);
    return smalllarge;
}