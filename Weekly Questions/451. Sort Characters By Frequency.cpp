// Question Link ---> https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap; // {char, frequency}
        multimap<int, char, greater<int>> sortedFreqsMap;
        string res = "";
        for (char chr : s) {
            freqMap[chr]++;
        }
        for (auto tuple : freqMap) {
            sortedFreqsMap.insert({tuple.second, tuple.first});
        }
        for (auto tuple : sortedFreqsMap) {
            int freq = tuple.first;
            while (freq--) {
                res += tuple.second;
            }
        }
        return res;
    }
};