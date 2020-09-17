// Question Link ---> https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        int size = nums.size();
        vector<string> sortedNums(size, "0");
        for (int i = 0; i < size; i++) {
            sortedNums[i] = to_string(nums[i]);
        }
        sort(sortedNums.begin(), sortedNums.end(), [](const string &a, const string &b){
            int minSize = min(a.size(), b.size());
            for (int i = 0; i < minSize; i++) {
                if (a[i] != b[i]) {
                    return (a[i] > b[i]);
                }
            }
            return (a+b) > (b+a);
        });
        for (string num : sortedNums) {
            res += num;
            if (res == "0") {
                return res;
            }
        }
        return res;
    }
};