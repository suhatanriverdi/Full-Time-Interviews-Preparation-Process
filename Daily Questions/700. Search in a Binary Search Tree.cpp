// QUESTION LINK ---> https://leetcode.com/problems/search-in-a-binary-search-tree/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return NULL;
        }
        if (val == root->val) {
            return root;
        }
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }
    }
};