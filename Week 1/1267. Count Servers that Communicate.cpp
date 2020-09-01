// Question Link ---> https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int M = grid.size(), N = grid[0].size(), res = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1 && isThereServerAround(grid, M, N, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
    
    bool isThereServerAround(vector<vector<int>> &grid, int M, int N, int i, int j) {
        queue<tuple<int, int, int>> cells; // {x, y, direction}
        cells.push({i + 1, j, 0}); // Up {1, 0}
        cells.push({i, j + 1, 1}); // Right {0, 1}
        cells.push({i - 1, j, 2}); // Down {-1, 0}
        cells.push({i, j - 1, 3}); // Left {0, -1}
        while (!cells.empty()) {
            tuple<int, int, int> current = cells.front();
            cells.pop();
            int nx = get<0>(current);
            int ny = get<1>(current);
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (grid[nx][ny] == 1) {
                    return true;
                }
                switch(get<2>(current)) {
                    case 0:
                        cells.push({get<0>(current) + 1, get<1>(current), 0});
                    break;

                    case 1:
                        cells.push({get<0>(current), get<1>(current) + 1, 1});
                    break;

                    case 2:
                        cells.push({get<0>(current) - 1, get<1>(current), 2});
                    break;

                    case 3:
                        cells.push({get<0>(current), get<1>(current) - 1, 3});
                    break;
                }
            }
        }
        return false;
    }
};