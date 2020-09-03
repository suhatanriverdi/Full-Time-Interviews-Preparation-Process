// Question Link ---> https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp(i, 1);
            res.push_back(temp);
            if (i > 2) {
                for (int j = 1; j < i - 1; j++) {
                    res[i - 1][j] = res[i - 2][j] + res[i - 2][j - 1];
                }
            }
        }
        return res;
    }
};