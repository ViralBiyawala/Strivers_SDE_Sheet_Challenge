int countSmallerOrEqual(vector<int>& row, int target) {
    int left = 0;
    int right = row.size() - 1;
    int count = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (row[mid] <= target) {
            count = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return count + 1;
}

int ninjaAndLadoos(vector<int>& row1, vector<int>& row2, int m, int n, int k) {
    int left = min(row1[0], row2[0]);
    int right = max(row1[m - 1], row2[n - 1]);

    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countSmallerOrEqual(row1, mid) + countSmallerOrEqual(row2, mid);

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
