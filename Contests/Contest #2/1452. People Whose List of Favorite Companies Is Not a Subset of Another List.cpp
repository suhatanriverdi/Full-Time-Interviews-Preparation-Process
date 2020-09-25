// Question Link ---> https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<set<string>> sets;
        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            set<string> tempSet;
            for (int j = 0; j < favoriteCompanies[i].size(); j++) {
                tempSet.insert(favoriteCompanies[i][j]);
            }
            sets.push_back(tempSet);
        }
        
        for (int i = 0; i < sets.size(); i++) {
            if (!isSubsetOfAnySet(sets, i)) {
                res.push_back(i);
            }
        }    
        
        return res;
    }
    
    bool isSubsetOfAnySet(vector<set<string>> &sets, int &currSetIdx) {
        for (int i = 0; i < sets.size(); i++) {
            if (i != currSetIdx && includes(sets[i].begin(), sets[i].end(), sets[currSetIdx].begin(), sets[currSetIdx].end())) {
                return true;
            }
        }
        return false;
    }
};