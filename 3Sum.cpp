#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findTriplets(std::vector<int> arr, int n, int K) {
    std::vector<std::vector<int>> triplets;
    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int targetSum = K - arr[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[left] + arr[right];

            if (currentSum == targetSum) {
                triplets.push_back({ arr[i], arr[left], arr[right] });

                while (left < right && arr[left] == arr[left + 1])
                    left++;
                while (left < right && arr[right] == arr[right - 1])
                    right--;

                left++;
                right--;
            } else if (currentSum < targetSum) {
                left++;
            } else {
                right--;
            }
        }

        while (i < n - 2 && arr[i] == arr[i + 1])
            i++;
    }

    return triplets;
}
