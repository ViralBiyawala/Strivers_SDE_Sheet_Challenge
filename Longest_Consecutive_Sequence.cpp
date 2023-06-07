#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if (n == 0)
        return 0;

    sort(arr.begin(), arr.end());

    int longestSequence = 1;
    int currentSequence = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            continue;
        else if (arr[i] == arr[i - 1] + 1)
            currentSequence++;
        else {
            longestSequence = max(longestSequence, currentSequence);
            currentSequence = 1;
        }
    }

    longestSequence = max(longestSequence, currentSequence);
    return longestSequence;
}
