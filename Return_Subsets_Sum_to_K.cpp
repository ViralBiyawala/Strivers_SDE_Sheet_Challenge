#include <vector>

void subsets(vector<int>& arr, vector<vector<int>>& ans, int n, int k, int i, int sum, vector<int>& v) {
    if (i == n) {
        if (sum == k) {
            ans.push_back(v);
        }
        return;
    }

    v.push_back(arr[i]);
    sum = sum + arr[i];
    subsets(arr, ans, n, k, i + 1, sum, v);
    v.pop_back();
    sum = sum - arr[i];
    subsets(arr, ans, n, k, i + 1, sum, v);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> ans;
    int i = 0;
    int sum = 0;
    vector<int> v;
    subsets(arr, ans, n, k, i, sum, v);
    return ans;
}
