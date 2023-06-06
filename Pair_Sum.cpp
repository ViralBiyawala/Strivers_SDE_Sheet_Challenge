#include <bits/stdc++.h>

std::vector<std::vector<int>> pairSum(std::vector<int>& arr, int s) {
   std::sort(arr.begin(), arr.end());
   std::vector<std::vector<int>> v;
   for (int i = 0; i < (arr.size() - 1); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
         if ((arr[i] + arr[j]) == s) {
            v.push_back({arr[i], arr[j]});
         }
         else if((arr[i] + arr[j]) > s)
            break;
      }
   }
   return v;
}
