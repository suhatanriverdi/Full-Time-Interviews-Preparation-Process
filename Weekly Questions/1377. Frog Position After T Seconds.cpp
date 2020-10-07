// Question Link ---> https://leetcode.com/problems/frog-position-after-t-seconds/

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n + 1, vector<int>());
        // Construct the adjacency graph
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        queue<int> nodesQueue;
        nodesQueue.push(1);
        vector<bool> visited(n + 1, false);
        vector<double> prob(n + 1, 0.0);
        prob[1] = 1.0;
        visited[1] = true;
        while (!nodesQueue.empty() && t-- > 0) {
            for (int s = nodesQueue.size(); s > 0; s--) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                int unvisitedChildCount = 0;
                for (int i = 0; i < graph[currentNode].size(); i++) {
                    if (visited[graph[currentNode][i]] == false) {
                        unvisitedChildCount++;
                    }
                }
                for (int child : graph[currentNode]) {
                    if (visited[child] == false) {
                        prob[child] = prob[currentNode] / unvisitedChildCount;
                        nodesQueue.push(child);
                        visited[child] = true;
                    }
                }
                if (unvisitedChildCount > 0) { // If we are not leaf, reset probability
                    prob[currentNode] = 0;
                }
            }
        }
        return prob[target];
    }
};