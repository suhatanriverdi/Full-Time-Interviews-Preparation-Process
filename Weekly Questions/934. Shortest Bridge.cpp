// Question Link ---> https://leetcode.com/problems/shortest-bridge/

class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 4 directions
public:
    int shortestBridge(vector<vector<int>>& A) {
        int sideLength = A.size();
        // Paint the first island
        paintFirstIsland(sideLength, A);
        // Expand the first island
        int currentLevel = 1;
        while (currentLevel++) {
            for (int i = 0; i < sideLength; i++) {
                for (int j = 0; j < A[i].size(); j++) {
                    if (A[i][j] == currentLevel && expandFirstIslandByOneLevel(i, j, sideLength, A, currentLevel) > 0) {
                        return currentLevel - 2;
                    }
                }
            }
        }
        return 0;
    }
    
        
    bool expandFirstIslandByOneLevel(int i, int j, int &sideLength, vector<vector<int>> &A, int &currentLevel) {
        for (auto dir : directions) {
            int nx = i + dir[0];
            int ny = j + dir[1];
            if (nx >= 0 && nx < sideLength && ny >= 0 && ny < sideLength) {
                if (A[nx][ny] == 0) {
                    A[nx][ny] = currentLevel + 1;
                }
                if (A[nx][ny] == 1) { // The second island found
                    return true;
                }
            }
        }
        return false;
    }
    
    void paintFirstIsland(int &sideLength, vector<vector<int>> &A) {
        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] == 1) { // First island found, mark borders
                    firstIslandCell = {i, j};
                    dfs(i, j, sideLength, A);
                    return;
                }
            }
        }
    }
    
    void dfs(int i, int j, int &sideLength, vector<vector<int>> &A) {
        if (i >= 0 && i < sideLength && j >= 0 && j < sideLength && A[i][j] == 1) {
            A[i][j] = 2;
            dfs(i, j + 1, sideLength, A);
            dfs(i, j - 1, sideLength, A);
            dfs(i + 1, j, sideLength, A);
            dfs(i - 1, j, sideLength, A);
        }
    }
};