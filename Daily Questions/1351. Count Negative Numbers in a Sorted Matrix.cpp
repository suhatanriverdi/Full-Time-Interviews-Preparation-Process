// QUESTION LINK ---> https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativeNumberCount = 0;
        for (vector<int> &row : grid) {
            for (int i = row.size() - 1; i >= 0 && row[i] < 0; i--) {
                negativeNumberCount++;
            }
        }
        return negativeNumberCount;
    }
};