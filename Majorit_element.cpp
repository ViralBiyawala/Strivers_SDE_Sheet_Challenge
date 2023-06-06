#include <iostream>
#include <unordered_map>

int findMajorityElement(int arr[], int n) {
    std::unordered_map<int, int> frequencyMap;

    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
        if (frequencyMap[arr[i]] > n / 2)
            return arr[i];
    }

    return -1;
}