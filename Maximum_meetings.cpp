#include <vector>
#include <algorithm>

vector<int> maximumMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, pair<int, int>>> meet;

    for (int i = 0; i < n; i++) {
        meet.push_back({end[i], {start[i], i + 1}});
    }

    sort(meet.begin(), meet.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.first < b.first)
            return true;
        else if (a.first > b.first)
            return false;
        else if (a.second.second < b.second.second)
            return true;
        else
            return false;
    });

    int t = -1;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (meet[i].second.first > t) {
            ans.push_back(meet[i].second.second);
            t = meet[i].first;
        }
    }

    return ans;
}
