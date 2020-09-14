// Question Link ---> https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

class Solution {
public:
    int maxCoins(vector<int> &piles) {
        int res = 0, n;
        sort(piles.begin(), piles.end(), greater<>());
        for (int i = 1; i < (piles.size() / 3) * 2; i+= 2) {
            res += piles[i];
        }
        return res;
    }
};