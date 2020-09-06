// Question Link ---> https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
    struct TreeNode {
        TreeNode *children[26];
        bool isWord = false;
    };
    TreeNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode *curNode = root;
        for (char curChr : word) {
            int idx = curChr - 'a';
            if (curNode->children[idx] == NULL) {
                curNode->children[idx] = new TreeNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    
    bool searchHelper(string &word, int idx, TreeNode *curNode) {
        if (idx == word.size() - 1) {
            return (curNode && curNode->isWord);
        }
        if (word[idx] == '.') {
            for (int j = 0; j < 26; j++) {
                if (curNode->children[j] && searchHelper(word, idx + 1, curNode->children[j])) {
                    return true;
                }
            }
        } 
        else {
            int key = word[idx] - 'a';
            if (curNode->children[key] == NULL) {
                return false;
            }
            return searchHelper(word, idx + 1, curNode->children[key]);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */