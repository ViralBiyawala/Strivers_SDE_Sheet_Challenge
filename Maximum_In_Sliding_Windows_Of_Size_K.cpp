#include <bits/stdc++.h>

std::vector<int> slidingWindowMaximum(std::vector<int> &nums, int &k) {
  std::vector<int> ans;
  std::deque<int> dq;
  int left = 0, right = 0;

  while (right < nums.size()) {
    while (!dq.empty() && nums[dq.back()] < nums[right])
      dq.pop_back();

    dq.push_back(right);

    if (right - left + 1 < k)
      right++;
    else if (right - left + 1 == k) {
      ans.push_back(nums[dq.front()]);

      if (nums[left] == nums[dq.front()])
        dq.pop_front();

      left++, right++;
    }
  }

  return ans;
}
