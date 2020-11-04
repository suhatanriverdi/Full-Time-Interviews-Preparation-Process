// Question Link ---> https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if (s[0] == '0') {
            return 0;
        }
        if (size == 1) {
            return 1;
        }
        // We know the string is valid now
        vector<int> DP(size + 1, 0);
        DP[0] = 1;
        DP[1] = (s[1] == '0' ? 0 : 1); // Check 10 or 20 case
        for (int i = 2; i <= size; i++) {
            int first = stoi(s.substr(i - 1, 1)); 
            int second = stoi(s.substr(i - 2, 2));
            // Check for second digit first, if it is not zero add +1
            if (first >= 1 && first <= 9) {
                DP[i] += DP[i - 1];
            }
            // Check for first digit
            if (second >= 10 && second <= 26) {
                DP[i] += DP[i - 2];
            }
        }
        return DP[size];
    }
};