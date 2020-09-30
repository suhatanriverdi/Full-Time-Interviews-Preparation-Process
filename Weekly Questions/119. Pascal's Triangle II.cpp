// Question Link ---> https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> temp(i + 1, 1);
            res.push_back(temp);
            if (i > 1) {
                for (int j = 1; j < i; j++) {
                    res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
                }
            }
        }
        return res[rowIndex];
    }
};