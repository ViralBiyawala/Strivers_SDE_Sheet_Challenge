#include <bits/stdc++.h> 

void wordBreakUtil(int index, const std::string& remaining, const std::unordered_map<std::string, int>& wordMap, const std::string& current, std::vector<std::string>& result) {
    if (index == remaining.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = index; i < remaining.size(); i++) {
        std::string word = remaining.substr(index, i - index + 1);
        
        if (wordMap.find(word) != wordMap.end() && wordMap.at(word) >= 1) {
            std::string newCurrent = current;
            if (!newCurrent.empty())
                newCurrent += " ";
            newCurrent += word;
            
            wordBreakUtil(i + 1, remaining, wordMap, newCurrent, result);
        }
    }
}

std::vector<std::string> wordBreak(const std::string& s, const std::vector<std::string>& dictionary) {
    std::vector<std::string> result;
    std::unordered_map<std::string, int> wordMap;
    
    for (const std::string& word : dictionary) {
        wordMap[word]++;
    }
    
    wordBreakUtil(0, s, wordMap, "", result);
    
    return result;
}
