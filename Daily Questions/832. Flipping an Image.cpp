// QUESTION LINK ---> https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (vector<int> &row : A) {
            reverse(row.begin(), row.end());
        }
        for (vector<int> &row : A) {
            for (int &val : row) {
                val ^= 1;
            }
        }
        return A;
    }
};