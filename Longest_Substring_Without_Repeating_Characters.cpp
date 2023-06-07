#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string s) {
    unordered_map<char, size_t> lastOccurrence;
    size_t startIdx = 0, maxLength = 0;
    
    for (size_t i = 0; i < s.size(); ++i) {
        auto it = lastOccurrence.find(s[i]);
        if (it == lastOccurrence.end()) {
            lastOccurrence.emplace_hint(it, s[i], i);
        } else {
            if (it->second >= startIdx) {
                maxLength = max(maxLength, i - startIdx);
                startIdx = it->second + 1;
            }
            it->second = i;
        }
    }
    
    maxLength = max(maxLength, s.size() - startIdx);
    return maxLength;
}
