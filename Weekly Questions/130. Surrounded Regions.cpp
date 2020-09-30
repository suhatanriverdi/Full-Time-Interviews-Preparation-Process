// Question Link ---> https://leetcode.com/problems/surrounded-regions/

// Solution 1 (Bad)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        if (M < 3) {
            return;
        }
        int N = board[0].size();
        set<vector<int>> unsafeOs;
        // Search O's in the borders and mark them
        for (int i = 0; i < N; i++) {
            if (board[0][i] == 'O') { // first row
                markOs(0, i, board, unsafeOs);
            }
            if (board[M - 1][i] == 'O') { // last row
                markOs(M - 1, i, board, unsafeOs);
            }
        }
        for (int j = 0; j < M; j++) {
            cout << j << " " << 0 << "    " << j << " " << N - 1 << endl;
            if (board[j][0] == 'O') { // first column
                markOs(j, 0, board, unsafeOs);
            }
            if (board[j][N - 1] == 'O') { // last column
                markOs(j, N - 1, board, unsafeOs);
            }
        }
        // Search other O's and flip to 'X'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O' && unsafeOs.count({i, j}) == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void markOs(int i, int j, vector<vector<char>> &board, set<vector<int>> &unsafeOs) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O' || unsafeOs.count({i, j}) > 0) {
            return;
        }
        unsafeOs.insert({i, j}); // We mark unsafe O's
        markOs(i + 1, j, board, unsafeOs);
        markOs(i - 1, j, board, unsafeOs);
        markOs(i, j + 1, board, unsafeOs);
        markOs(i, j - 1, board, unsafeOs);
    }
};

// Solution 2 (Best)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        if (M < 3) {
            return;
        }
        int N = board[0].size();
        // Search O's in the borders and mark them
        for (int i = 0; i < N; i++) {
            if (board[0][i] == 'O') { // first row
                markOs(0, i, board);
            }
            if (board[M - 1][i] == 'O') { // last row
                markOs(M - 1, i, board);
            }
        }
        for (int j = 0; j < M; j++) {
            if (board[j][0] == 'O') { // first column
                markOs(j, 0, board);
            }
            if (board[j][N - 1] == 'O') { // last column
                markOs(j, N - 1, board);
            }
        }
        // Search other O's and flip to 'X'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        // Search other 1's and flip to 'O'
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void markOs(int i, int j, vector<vector<char>> &board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        board[i][j] = '1';
        markOs(i + 1, j, board);
        markOs(i - 1, j, board);
        markOs(i, j + 1, board);
        markOs(i, j - 1, board);
    }
};