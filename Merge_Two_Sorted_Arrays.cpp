#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> mergedArray;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }
    while (i < m) {
        mergedArray.push_back(arr1[i]);
        i++;
    }
    while (j < n) {
        mergedArray.push_back(arr2[j]);
        j++;
    }
    return mergedArray;
}