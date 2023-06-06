#include <bits/stdc++.h>

using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;
    vector<int> v(n+1, 0);

    for (auto it : arr)
        v[it]++;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            ans.first = i;
        else if (v[i] == 2)
            ans.second = i;
    }

    return ans;
}