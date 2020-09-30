// QUESTION LINK ---> https://leetcode.com/problems/rank-transform-of-an-array/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) {
            return arr;
        }
        vector<int> arrUnsorted = arr;
        sort(arr.begin(), arr.end());
        int rank = 1;
        unordered_map<int, int> numRankMap;
        numRankMap[arr[0]] = rank;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1]) {
                rank++;
            }
            numRankMap[arr[i]] = rank;
        }
        for (int i = 0; i < arrUnsorted.size(); i++) {
            arrUnsorted[i] = numRankMap[arrUnsorted[i]];
        }
        return arrUnsorted;
    }
};