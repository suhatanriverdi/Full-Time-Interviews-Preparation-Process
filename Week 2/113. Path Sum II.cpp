// Question Link ---> https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> pathVals;
        accumulateTreeSum(root, sum, res, pathVals);
        return res;
    }
    
    void accumulateTreeSum(TreeNode *currentNode, int sumByFar, vector<vector<int>> &res, vector<int> &pathVals) {
        if (!currentNode) {
            return;
        }
        sumByFar -= currentNode->val;
        pathVals.push_back(currentNode->val);
        // If we are at the leaf node
        if (!currentNode->right && !currentNode->left && sumByFar == 0) {
            res.push_back(pathVals);
        }
        accumulateTreeSum(currentNode->left, sumByFar, res, pathVals);
        accumulateTreeSum(currentNode->right, sumByFar, res, pathVals);
        pathVals.pop_back(); // Backtracking
    }
};