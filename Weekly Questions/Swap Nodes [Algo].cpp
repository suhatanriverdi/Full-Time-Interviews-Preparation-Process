// Question Link ---> https://www.hackerrank.com/challenges/swap-nodes-algo/problem

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void swapNodesAtDepth(unordered_map<int, vector<TreeNode*>> &depthNodes, int query) {
    for (auto pair : depthNodes) {
        if (pair.first % query == 0) {
            for (TreeNode* toSwap : depthNodes[pair.first]) {
                TreeNode* temp = toSwap->left;
                toSwap->left = toSwap->right;
                toSwap->right = temp;
            }
        }
    }
}

void inOrderTraversal(TreeNode *cur, vector<int> &seq) {
    if (cur == NULL) {
        return;
    }
    inOrderTraversal(cur->left, seq);
    seq.push_back(cur->val);
    inOrderTraversal(cur->right, seq);
}

TreeNode* construcBinarytTree(vector<vector<int>> &nodes, unordered_map<int, vector<TreeNode*>> &depthNodes) {
    TreeNode *root = new TreeNode(1);
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    int ithNode = 0, depth = 1, nodeSize = nodes.size();
    while (!nodesQueue.empty()) {
        for (int i = nodesQueue.size(); i > 0; i--) {
            TreeNode *cur = nodesQueue.front();
            nodesQueue.pop();
            if (cur) {
                depthNodes[depth].push_back(cur);
            }
            if (ithNode < nodeSize) {
                if (nodes[ithNode][0] != -1) {
                    cur->left = new TreeNode(nodes[ithNode][0]);
                    nodesQueue.push(cur->left);
                }
                if (nodes[ithNode][1] != -1) {
                    cur->right = new TreeNode(nodes[ithNode][1]);
                    nodesQueue.push(cur->right);
                }
                ithNode++;
            } else {
                return root;
            }
        }
        depth++;
    }
    return root;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    unordered_map<int, vector<TreeNode*>> depthNodes;
    TreeNode *root = construcBinarytTree(indexes, depthNodes);
    vector<vector<int>> result;
    for (int query : queries) {
        swapNodesAtDepth(depthNodes, query);
        vector<int> tempSeq;
        inOrderTraversal(root, tempSeq);
        result.push_back(tempSeq);
    }
    return result;
}