// Question Link ---> https://leetcode.com/problems/binary-watch/

class Solution {
public:
    vector<string> readBinaryWatch(int n) {
        if (n > 8) {
            return {};
        }
        vector<string> res;
        int tempCnt = 0, tempCnt2 = 0;
        string tempStr = "", tempStr2 = "00";
        for (int h = 0; h <= 11; h++) {
            tempStr = bitset<4>(h).to_string();
            tempCnt = count(tempStr.begin(), tempStr.end(), '1');
            for (int m = 0; m <= 59; m++) {
                tempStr2 = bitset<6>(m).to_string();
                tempCnt2 = count(tempStr2.begin(), tempStr2.end(), '1');
                if (tempCnt + tempCnt2 == n) {
                    string min = (m < 10 ? ("0" + to_string(m)) : to_string(m));
                    res.push_back(to_string(h) + ":" + min);
                }
            }
        }
        return res;
    }
};