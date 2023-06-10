#include <vector>
#include <string>
#include <algorithm>

void backtrack(string& s, int start, vector<string>& result) {
    if (start == s.length() - 1) {
        result.push_back(s);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        swap(s[start], s[i]);
        backtrack(s, start + 1, result);
        swap(s[start], s[i]); // backtrack (restore the original string)
    }
}

vector<string> findPermutations(string& s) {
    vector<string> result;
    backtrack(s, 0, result);
    return result;
}
