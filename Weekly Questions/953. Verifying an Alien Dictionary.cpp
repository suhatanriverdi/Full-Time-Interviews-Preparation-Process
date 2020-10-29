// Question Link ---> https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> letterValueMap;
        for (int i = 0; i < order.size(); i++) {
            letterValueMap[order[i]] += i;
        }
        for (int i = 1; i < words.size(); i++) {
            if (!isOrdered(words[i - 1], words[i], letterValueMap)) {
                return false;
            }
        }
        return true;
    }
    
    bool isOrdered(string &a, string &b, unordered_map<char, int> &letterValueMap) {
        int sizeA = a.size(), sizeB = b.size(), minSize = min(sizeA, sizeB);
        for (int i = 0; i < minSize; i++) {
            int valA = letterValueMap[a[i]];
            int valB = letterValueMap[b[i]];
            if (valA < valB) {
                return true;
            }
            if (valA > valB) {
                return false;
            }
        }
        if (sizeA > sizeB) {
            return false;
        }
        return true;
    }
};