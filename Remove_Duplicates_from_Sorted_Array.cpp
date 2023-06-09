#include <iostream>
#include <vector>
#include <algorithm>

int removeDuplicates(vector<int> &arr, int n) {
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
 	arr.resize(distance(arr.begin(), arr.end()));
	return arr.size();
}