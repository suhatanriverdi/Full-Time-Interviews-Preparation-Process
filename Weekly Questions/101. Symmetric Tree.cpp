// Question Link ---> https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> nodesQ;
        nodesQ.push(root);
        while (!nodesQ.empty()) {
            vector<string> symStr;
            for (int i = nodesQ.size(); i > 0; i--) {
                TreeNode* cur = nodesQ.front();
                nodesQ.pop();
                if (cur->left) {
                    nodesQ.push(cur->left);
                    symStr.push_back(to_string(abs(cur->left->val)));
                } else {
                    symStr.push_back("N");
                }
                if (cur->right) {
                    nodesQ.push(cur->right);
                    symStr.push_back(to_string(abs(cur->right->val)));
                } else {
                    symStr.push_back("N");
                }
            }
            if (!isPalindrome(symStr)) {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(vector<string> &str) {
        int size = str.size();
        for (int i = 0; i < size / 2; i++) {
            if (str[i] != str[size - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};