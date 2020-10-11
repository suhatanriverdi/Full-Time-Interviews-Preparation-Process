// Question Link ---> https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> digitMP; // {digit, frequency}
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (guess[i] != secret[i]) {
                digitMP[secret[i]]++;
            }
        }
        for (int i = 0; i < guess.size(); i++) {
            if (guess[i] == secret[i]) {
                bulls++;
            }
            else {
                if (digitMP[guess[i]] > 0) {
                    cows++;
                    digitMP[guess[i]]--;
                } 
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};