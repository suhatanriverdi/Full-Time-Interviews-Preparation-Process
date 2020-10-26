// Question Link ---> https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], prevSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prevSum = max(prevSum + nums[i], nums[i]);
            result = max(result, prevSum);
        }
        return result;
    }
};