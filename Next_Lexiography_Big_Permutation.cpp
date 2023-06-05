#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i = n - 2;
    while (i >= 0 && permutation[i] >= permutation[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = n - 1;
        while (permutation[j] <= permutation[i]) {
            j--;
        }
        swap(permutation[i], permutation[j]);
    }
    reverse(permutation.begin() + i + 1, permutation.end());
    return permutation;
}
