int longestSubSeg(vector<int>& arr, int n, int k) {
    int left = 0;
    int right = 0;
    int zerosCount = 0;
    int maxOnesCount = 0;

    while (right < n) {
        if (arr[right] == 0) {
            zerosCount++;
        }

        while (zerosCount > k) {
            if (arr[left] == 0) {
                zerosCount--;
            }
            left++;
        }

        maxOnesCount = max(maxOnesCount, right - left + 1);
        right++;
    }

    return maxOnesCount;
}
