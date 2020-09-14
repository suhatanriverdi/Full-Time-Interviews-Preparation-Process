// Question Link ---> https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res = {};
        map<int, int> numFreq;
        int lastVisitedSector = 0, maxRepeated = 0, start, end;
        for (int i = 0; i + 1 < rounds.size(); i++) {
            start = rounds[i];
            end = rounds[i + 1];
            for (; start != end; start++) {
                if (lastVisitedSector != start) {
                    numFreq[start]++;
                }
                if (start == n) {
                    start = 0;
                }
            }
            if (lastVisitedSector != start) {
                numFreq[start]++;
            }
            lastVisitedSector = end;
        }
        for (auto pair : numFreq) {
            if (pair.second >= maxRepeated) {
                maxRepeated = pair.second;
            }
        }
        for (auto pair : numFreq) {
            if (maxRepeated == pair.second) {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};