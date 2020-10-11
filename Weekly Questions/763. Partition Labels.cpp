// Question Link ---> https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, vector<int>> lettersMP; // {letter, {start, end}}
        vector<int> result;
        int size = S.size();
        for (int i = 0; i < size; i++) {
            if (lettersMP.find(S[i]) == lettersMP.end()) {
                lettersMP.insert({S[i], {i, i}});
            } else {
                lettersMP[S[i]][1] = i;
            }
        }
        set<vector<int>> rangeSet;
        for (auto &pair : lettersMP) {
            rangeSet.insert(pair.second);
        }
        bool end = false, overlapped = false;
        while (rangeSet.size() > 0) {
            overlapped = false;
            vector<int> tmp = *rangeSet.begin();
            rangeSet.erase(rangeSet.begin());
            for (auto &cur : rangeSet) {
                if ((tmp[0] <= cur[1] && tmp[1] >= cur[0])) {
                    tmp = {min(tmp[0], cur[0]), max(tmp[1], cur[1])};
                    rangeSet.erase(cur);
                    rangeSet.insert({tmp[0], tmp[1]});
                    overlapped = true;
                    break;
                }
            }
            if (overlapped == false) {
                result.push_back(tmp[1] - tmp[0] + 1);
            }
        }
        return result;
    }
};