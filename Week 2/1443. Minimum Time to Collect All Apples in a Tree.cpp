// Question Link ---> https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n, vector<int>());
        unordered_map<int, int> nodeCameFrom; // {node, parent}
        // Construct the Adjacency List Graph
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        fillNodesBFS(nodeCameFrom, graph, n);
        queue<int> nodesQueue;
        // Push only nodes that have an apple into Queue
        for (int i = 0; i < hasApple.size(); i++) {
            if (hasApple[i]) {
                nodesQueue.push(i);
            }
        }
        set<pair<int, int>> uniqueEdges;
        while (!nodesQueue.empty()) {
            int curNode = nodesQueue.front();
            nodesQueue.pop();
            int parent = nodeCameFrom[curNode];
            for (; parent != 0; curNode = parent, parent = nodeCameFrom[parent]) {
                uniqueEdges.insert({curNode, parent});
            }
            uniqueEdges.insert({curNode, parent});
        }
        uniqueEdges.erase({0, 0});
        return uniqueEdges.size() * 2;
    }
    
    void fillNodesBFS(unordered_map<int, int> &nodeCameFrom, vector<vector<int>> &graph, int &n) {
        queue<int> nodesQueue;
        vector<bool> isVisited(n, false);
        nodesQueue.push(0);
        isVisited[0] = true;
        while (!nodesQueue.empty()) {
            int curNode = nodesQueue.front();
            nodesQueue.pop();
            for (int childred : graph[curNode]) {
                if (isVisited[childred] == false) {
                    nodesQueue.push(childred);
                    isVisited[childred] = true;
                    nodeCameFrom[childred] = curNode;
                }
            }
        }
    }
};