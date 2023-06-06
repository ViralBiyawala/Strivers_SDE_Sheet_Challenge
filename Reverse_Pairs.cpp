#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int left, int mid, int right) {
    int count = 0;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] > 2LL * arr[j]) {
            count += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }

    // Merge the two sorted halves
    std::vector<int> merged;
    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            merged.push_back(arr[i]);
            i++;
        } else {
            merged.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        merged.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        merged.push_back(arr[j]);
        j++;
    }

    // Copy the merged array back to the original array
    for (int k = left; k <= right; k++) {
        arr[k] = merged[k - left];
    }

    return count;
}

int mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int count = mergeSort(arr, left, mid) + mergeSort(arr, mid + 1, right) + merge(arr, left, mid, right);

    return count;
}

int reversePairs(vector<int>& arr,int n) {
    return mergeSort(arr, 0, n - 1);
}
