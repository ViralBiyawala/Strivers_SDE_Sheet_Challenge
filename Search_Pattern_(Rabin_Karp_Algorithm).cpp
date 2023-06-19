#include <bits/stdc++.h>
using namespace std;
#define d 256

vector<int> stringMatch(string &str, string &pat) {

  int n = str.size(), m = pat.size();
  vector<int> ans;

  int q = INT_MAX, h = (int) pow(d, m - 1);

  int hP = 0, hS = 0;
  for (int i = 0; i < m; i++) {
    hP = (d * hP + pat[i]) % q;
    hS = (d * hS + str[i]) % q;
  }

  for (int i = 0; i <= n - m; i++) {
    if (hP == hS) {
      int j = 0;
      for (; j < m; j++)
        if (str[i + j] != pat[j])
          break;

      if (j == m)
        ans.push_back(i+1);
    }

    if (i < n - m) {
      hS = (d * (hS - str[i] * h) + str[i + m]) % q;

      if (hS < 0)
        hS += q;
    }
  }

  return ans;
}