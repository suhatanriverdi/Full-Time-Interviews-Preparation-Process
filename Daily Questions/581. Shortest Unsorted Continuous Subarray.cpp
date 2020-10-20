// QUESTION LINK ---> https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size(), result = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int firstIndex = size, lastIndex = 0;
        bool alreadySorted = true;
        for (int i = 0; i < size; i++) {
            if (nums[i] != sorted[i]) {
                firstIndex = min(firstIndex, i);
                lastIndex = max(lastIndex, i);
                alreadySorted = false;
            }
        }
        if (alreadySorted) {
            return 0;
        }
        result = abs(lastIndex - firstIndex) + 1;
        return result;
    }
};