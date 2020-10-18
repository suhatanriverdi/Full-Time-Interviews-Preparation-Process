// Question Link ---> https://leetcode.com/problems/reorganize-string/
class Solution {
public:
    string reorganizeString(string S) {
        if (S.size() <= 1) {
            return S;
        }
        unordered_map<char, int> letterFreqMP;
        for (char c : S) {
            letterFreqMP[c]++;
        }
        priority_queue<pair<int, char>> freqLetterPQ;
        for (auto tuple : letterFreqMP) {
            freqLetterPQ.push({tuple.second, tuple.first});
        }
        string result = "";
        while (!freqLetterPQ.empty()) {
            pair<int, char> A = freqLetterPQ.top();
            freqLetterPQ.pop();
            A.first--;
            result += A.second;
            if (freqLetterPQ.empty()) {
                if (A.first > 0) {
                    return "";
                }
                return result;
            }
            pair<int, char> B = freqLetterPQ.top();
            freqLetterPQ.pop();
            B.first--;
            result += B.second;
            if (A.first > 0) {
                freqLetterPQ.push(A);
            }
            if (B.first > 0) {
                freqLetterPQ.push(B);
            }
        }
        return result;
    }
};