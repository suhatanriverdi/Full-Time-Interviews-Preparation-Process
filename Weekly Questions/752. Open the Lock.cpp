// Question Link ---> https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        int result = 0;
        if (deadendsSet.find("0000") != deadendsSet.end()) {
            return -1;
        }
        queue<string> wheelQueue;
        wheelQueue.push("0000");
        visited.insert("0000");
        while (!wheelQueue.empty()) {
            int levelSize = wheelQueue.size();
            while (levelSize--) {
                string up, down, currentWheel = wheelQueue.front();
                wheelQueue.pop();
                if (currentWheel == target) {
                    return result;
                }
                for (int i = 0; i < 4; i++) {
                    down = up = currentWheel;
                    char upCh = up[i], downCh = down[i];
                    up[i] = (upCh == '9' ? '0' : upCh + 1);
                    down[i] = (downCh == '0' ? '9' : downCh - 1);
                    if (visited.find(up) == visited.end() && deadendsSet.find(up) == deadendsSet.end()) {
                        wheelQueue.push(up);
                        visited.insert(up);
                    }
                    if (visited.find(down) == visited.end() && deadendsSet.find(down) == deadendsSet.end()) {
                        wheelQueue.push(down);
                        visited.insert(down);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};
