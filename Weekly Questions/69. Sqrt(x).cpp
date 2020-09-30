// Question Link ---> https://leetcode.com/problems/sqrtx/

class Solution {
public:
    // Find the closest and smaller perfect square to us
    int mySqrt(int x) {
        long long int sqr, i;
        for (; x >= 0; x--) {
            sqr = sqrt(x);
            if (sqr * sqr == x) {
                return sqr;
            }
        }
        return -1;
    }
};