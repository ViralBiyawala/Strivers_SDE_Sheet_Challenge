#include <vector>
#include <algorithm>

void backtrack(int index, vector<int>& arr, vector<int>& subset, vector<vector<int>>& subsets) {
    subsets.push_back(subset);

    for (int i = index; i < arr.size(); i++) {
        if (i > index && arr[i] == arr[i - 1]) {
            continue;
        }

        subset.push_back(arr[i]);
        backtrack(i + 1, arr, subset, subsets);
        subset.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int>& arr) {
    sort(arr.begin(), arr.end());

    vector<vector<int>> subsets;
    vector<int> subset;

    backtrack(0, arr, subset, subsets);

    return subsets;
}
