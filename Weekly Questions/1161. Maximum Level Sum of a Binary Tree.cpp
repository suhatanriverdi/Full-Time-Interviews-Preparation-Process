// Question Link ---> https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodesQ;
        nodesQ.push(root);
        vector<vector<int>> levelSumVec;
        levelSumVec.push_back({1, root->val});
        int curLevelSum = 0, curLevel = 1;
        while (!nodesQ.empty()) {
            curLevel++;
            curLevelSum = 0;
            for (int i = nodesQ.size(); i > 0; i--) {
                TreeNode* cur = nodesQ.front();
                nodesQ.pop();
                if (cur->left) {
                    nodesQ.push(cur->left);
                    curLevelSum += cur->left->val;
                }
                if (cur->right) {
                    nodesQ.push(cur->right);
                    curLevelSum += cur->right->val;
                }
            }
            levelSumVec.push_back({curLevel, curLevelSum});
        }
        levelSumVec.pop_back();
        int maxLevel = 1, maxSum = root->val;           
        for (vector<int> it : levelSumVec) {
            if (it[1] > maxSum) {
                maxSum = it[1];
                maxLevel = it[0];
            }
        }
        return maxLevel;
    }
};