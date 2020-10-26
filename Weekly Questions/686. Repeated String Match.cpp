// Question Link ---> https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int Bsize = b.size(), repeatingTime = 1;
        string superset = a, subset = b;
        if (superset.find(subset) != string::npos) {
            return repeatingTime;
        }
        while (superset.size() < Bsize) {
            superset += a;
            repeatingTime++;
            if (superset.find(subset) != string::npos) {
                return repeatingTime;
            }
        }
        superset += a;
        repeatingTime++;
        if (superset.find(subset) != string::npos) {
            return repeatingTime;
        }
        return -1;
    }
};