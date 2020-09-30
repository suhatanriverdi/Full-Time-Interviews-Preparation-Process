// Question Link ---> https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Recursion Solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->right) {
            return 1 + minDepth(root->left);
        }
        if (!root->left) {
            return 1 + minDepth(root->right);
        }
        return 1 + min(minDepth(root->right), minDepth(root->left));
    }
};

// BFS Solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> nodesQueue;
        root->val = 1;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();
            if (!currentNode->left && !currentNode->right) { // Leaf Node
                return currentNode->val;
            }
            if (currentNode->left) {
                currentNode->left->val = currentNode->val + 1;
                nodesQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                currentNode->right->val = currentNode->val + 1;
                nodesQueue.push(currentNode->right);
            }
        }
        return 0;
    }
};