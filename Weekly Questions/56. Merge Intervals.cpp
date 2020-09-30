// Question Link ---> https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res = {};
        if (intervals.size() == 0) {
            return res;
        }
        
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] < b[0]);
        });
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0]; 
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]); 
            } else {
                res.push_back(intervals[i - 1]);
            }
        }
        
        if (res.size() == 0) {
            res.push_back(intervals.back());
        }
        
        
        if (res.back() != intervals.back()) {
            res.push_back(intervals.back());
        }
        
        return res;
    }
};