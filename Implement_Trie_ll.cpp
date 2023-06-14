class TrieNode {
public:
    TrieNode* children[26];
    int endWith;
    int countPrefix;

    TrieNode() {
        endWith = 0;
        countPrefix = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insertWord(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->countPrefix++;
            root->endWith++;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            TrieNode* newTrieNode = new TrieNode();
            root->children[index] = newTrieNode;
            child = root->children[index];
        }
        root->countPrefix++;
        insertWord(child, word.substr(1));
    }

    int countWords(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->endWith;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return 0;
        }

        return countWords(child, word.substr(1));
    }

    int countWordsWithPrefix(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->countPrefix;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return 0;
        }

        return countWordsWithPrefix(child, word.substr(1));
    }

    void removeWords(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->countPrefix--;
            root->endWith--;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            root->countPrefix--;
            child = root->children[index];
        }
        else {
            return;
        }

        removeWords(child, word.substr(1));
    }

    void insert(string& word) {
        insertWord(root, word);
    }

    int countWordsEqualTo(string& word) {
        return countWords(root, word);
    }

    int countWordsStartingWith(string& word) {
        return countWordsWithPrefix(root, word);
    }

    void erase(string& word) {
        removeWords(root, word);
    }
};
