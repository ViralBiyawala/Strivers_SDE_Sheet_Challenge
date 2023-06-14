#include <bits/stdc++.h> 

class Node {
public:
    int data;
    Node* child[2];

    Node(int data) {
        this->data = data;
        for (int i = 0; i < 2; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(int num) {
        Node* prev = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            Node* child;
            if (prev->child[bit] == NULL) {
                child = new Node(bit);
                prev->child[bit] = child;
            }
            else {
                child = prev->child[bit];
            }
            prev = child;
        }
    }

    int findMax(int num) {
        int val = 0;
        Node* prev = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            Node* child;
            if (bit & 1) {
                if (prev->child[0]) {
                    child = prev->child[0];
                    val = val | (1 << i);
                }
                else {
                    child = prev->child[1];
                }
            }
            else {
                if (prev->child[1]) {
                    child = prev->child[1];
                    val = val | (1 << i);
                }
                else {
                    child = prev->child[0];
                }
            }
            prev = child;
        }
        return val;
    }
};

int maximumXor(vector<int> A) {
    Trie t;
    for (int i = 0; i < A.size(); i++) {
        t.insert(A[i]);
    }
    int ans = 0;
    int val = 0;
    for (int i = 0; i < A.size(); i++) {
        val = t.findMax(A[i]);
        ans = max(ans, val);
    }
    return ans;
}
