// Question Link ---> https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        vector<int> res = {};
        if (!root) {
            return res;
        }
        while (!nodesQueue.empty()) {
            int currentQueueSize = nodesQueue.size();
            int levelMax = INT_MIN;
            while (currentQueueSize-- > 0) {
                TreeNode *currentNode = nodesQueue.front();
                nodesQueue.pop();
                levelMax = max(levelMax, currentNode->val);
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }
            res.push_back(levelMax);
        }
        return res;
    }
};