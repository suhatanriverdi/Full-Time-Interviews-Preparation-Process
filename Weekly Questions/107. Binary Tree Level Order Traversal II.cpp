// Question Link ---> https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size();
            vector<int> currentLevel;
            while (levelSize--) {
                TreeNode *currentNode = nodesQueue.front();
                nodesQueue.pop();
                currentLevel.push_back(currentNode->val);
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);  
                }
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);  
                }
            }
            reverse(currentLevel.begin(), currentLevel.end());
            res.push_back(currentLevel);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};