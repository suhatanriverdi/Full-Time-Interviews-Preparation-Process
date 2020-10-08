// Question Link ---> https://leetcode.com/problems/clone-graph/

// BFS Solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return node;
        }
        unordered_map<Node*, Node*> clone; // {original node, its clone}, also used for visited check
        queue<Node*> nodesQ;
        nodesQ.push(node);
        clone.insert({ node, new Node(node->val) });
        while (!nodesQ.empty()) {
            Node* cur = nodesQ.front();
            nodesQ.pop();
            for (Node* neighbor : cur->neighbors) {
                if (clone.find(neighbor) == clone.end()) {
                    nodesQ.push(neighbor);
                    clone.insert({ neighbor, new Node(neighbor->val) });
                }
                clone[cur]->neighbors.push_back(clone[neighbor]);
            }
        }
        return clone[node];
    }
};

// DFS Solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> clone; // {original node, its clone}, also used for visited check
        return dfs(node, clone);
    }
    
    Node* dfs(Node *cur, unordered_map<Node*, Node*> &clone) {
        if (!cur) {
            return NULL;
        }
        if (clone.find(cur) == clone.end()) { // If not visited
            clone[cur] = new Node(cur->val);
            for (Node* child : cur->neighbors) {
                clone[cur]->neighbors.push_back( dfs(child, clone) );
            }
        }
        return clone[cur];
    }
};