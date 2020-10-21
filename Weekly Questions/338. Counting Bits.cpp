// Question Link ---> https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) {
            return {0};
        }
        if (num == 1) {
            return {0, 1};
        }
        vector<int> DP(num + 1, 0);
        DP[0] = 0;
        DP[1] = 1;
        for (int i = 2, back = 0; i <= num; i++, back++) {
            if ((i & (i - 1)) == 0) { // If i is power of two, reset back
                back = 0;
            }
            DP[i] = DP[back] + 1;
        }
        return DP;
    }
};