#include <bits/stdc++.h>
using namespace std;

bool compareIntervals(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compareIntervals);

    vector<vector<int>> mergedIntervals;
    int n = intervals.size();

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (!mergedIntervals.empty() && start <= mergedIntervals.back()[1]) {
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], end);
        } else {
            mergedIntervals.push_back({start, end});
        }
    }

    return mergedIntervals;
}
