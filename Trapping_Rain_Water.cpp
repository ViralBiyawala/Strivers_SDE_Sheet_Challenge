long getTrappedWater(long *arr, int n) {
    long totalWater = 0;

    if (n <= 2) {
        return totalWater;
    }

    long left = 0;
    long right = n - 1;
    long leftMax = 0;
    long rightMax = 0;

    while (left < right) {
        if (arr[left] <= arr[right]) {
            leftMax = (leftMax > arr[left]) ? leftMax : arr[left];
            totalWater += leftMax - arr[left];
            left++;
        } else {
            rightMax = (rightMax > arr[right]) ? rightMax : arr[right];
            totalWater += rightMax - arr[right];
            right--;
        }
    }

    return totalWater;
}
