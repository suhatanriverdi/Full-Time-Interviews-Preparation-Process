// Question Link ---> https://leetcode.com/problems/binary-search-tree-iterator/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    vector<int> sorted;
    int iterator, size;
public:
    BSTIterator(TreeNode* root) {
        iterator = 0;
        fillSortedVector(root);
        size = sorted.size();
    }
    
    void fillSortedVector(TreeNode *cur) {
        if (!cur) {
            return;
        }
        fillSortedVector(cur->left);
        sorted.push_back(cur->val);
        fillSortedVector(cur->right);
    }
    
    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            return sorted[iterator++];
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iterator < size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */