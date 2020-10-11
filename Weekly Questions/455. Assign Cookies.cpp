// Question Link ---> https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        vector<int> enoughCookies;
        for (int c : s) {
            if (c >= g[0]) {
                enoughCookies.push_back(c);
            }
        }
        sort(enoughCookies.begin(), enoughCookies.end());
        int res = 0, ithChild = 0, ithCookie = 0;
        while (ithChild < g.size() && ithCookie < enoughCookies.size()) {
            if (g[ithChild] <= enoughCookies[ithCookie]) {
                res++;
                ithCookie++;
                ithChild++;
            } else {
                ithCookie++;
            }
        }
        return res;
    }
};