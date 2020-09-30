// QUESTION LINK ---> https://leetcode.com/problems/implement-trie-prefix-tree/

Solution 1: Using unordered_map

// Trie Node Struct
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isCompleteWord = false;
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curNode = root;
        for (char curChr : word) {
            if (curNode->children.count(curChr) == 0) {
                curNode->children[curChr] = new TrieNode();
            }
            curNode = curNode->children[curChr];
        }
        curNode->isCompleteWord = true; // Mark last node as a word
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curNode = root;
        for (char curChr : word) {
            if (curNode->children.count(curChr) == 0) {
                return false;
            }
            curNode = curNode->children[curChr];
        }
        return (curNode && curNode->isCompleteWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curNode = root;
        for (char curChr : prefix) {
            if (curNode->children.count(curChr) == 0) {
                return false;
            }
            curNode = curNode->children[curChr];
        }
        return true;
    }
};
Solution 2 (Better): Using Array with size 26

// Trie Node Struct
struct TrieNode {
    TrieNode* children[26];
    bool isCompleteWord = false;
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curNode = root;
        for (char curChr : word) {
            int idx = curChr - 'a';
            if (curNode->children[idx] == NULL) {
                curNode->children[idx] = new TrieNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->isCompleteWord = true; // Mark last node as a word
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curNode = root;
        for (char curChr : word) {
            int idx = curChr - 'a';
            if (curNode->children[idx] == NULL) {
                return false;
            }
            curNode = curNode->children[idx];
        }
        return (curNode && curNode->isCompleteWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curNode = root;
        for (char curChr : prefix) {
            int idx = curChr - 'a';
            if (curNode->children[idx] == NULL) {
                return false;
            }
            curNode = curNode->children[idx];
        }
        return true;
    }
};