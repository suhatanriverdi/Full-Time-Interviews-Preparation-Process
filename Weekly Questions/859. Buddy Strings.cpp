// Question Link ---> https://leetcode.com/problems/buddy-strings/

// Solution 1
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        unordered_map<char, int> aFreq, bFreq;
        for (int i = 0; i < A.size(); i++) {
            aFreq[A[i]]++;
            bFreq[B[i]]++;
        }
        if (aFreq != bFreq) {
            return false;
        }
        int misCnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                misCnt++;
            }
            if (misCnt > 2) {
                return false;
            }
        }
        if (misCnt == 2) {
            return true;
        }
        if (misCnt == 1 || !consecutiveLetterCheck(aFreq)) {
            return false;
        }
        return true;
    }
    
    bool consecutiveLetterCheck(unordered_map<char, int> mp) {
        for (auto elem : mp) {
            if (elem.second > 1) {
                return true;
            }
        }
        return false;
    }
};


// Solution 2 (Better)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        
        // If A & B are equal and A has duplicates -> A = "aba", B = "aba", we can swap a's
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) {
            return true;
        }
        
        // Save indices where letters are different
        vector<int> diff;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                diff.push_back(i);
            }
        }
        return (diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]);
    }
};