#include <vector>
#include <string>

bool isPalindrome(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void partitionPalindrome(string& s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i)) {
            string palindrome = s.substr(start, i - start + 1);
            current.push_back(palindrome);
            partitionPalindrome(s, i + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string& s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionPalindrome(s, 0, current, result);
    return result;
}
