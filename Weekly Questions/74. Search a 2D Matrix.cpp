// Question Link ---> https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size(), k = 0;
        if (size == 0) {
            return false;
        }
        vector<int> sorted(matrix.size() * matrix[0].size(), 0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < matrix[i].size(); j++, k++) {
                sorted[k] = matrix[i][j];
            }   
        }
        return binarySearch(sorted, target);
    }
    
    bool binarySearch(vector<int> &sorted, int &target) {
        int L = 0, R = sorted.size() - 1, mid;
        while (L <= R) {
            mid = (L + R) / 2;
            if (sorted[mid] == target) {
                return true;
            }
            if (target > sorted[mid]) {
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        return false;
    }
};