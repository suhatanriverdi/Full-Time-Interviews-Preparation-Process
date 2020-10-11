// Question Link ---> https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stonesPQ;
        for (int stone : stones) {
            stonesPQ.push(stone);
        }
        while (stonesPQ.size() > 1) {
            int A = stonesPQ.top();
            stonesPQ.pop();
            if (stonesPQ.size() <= 0) {
                break;
            }
            int B = stonesPQ.top();
            stonesPQ.pop();
            stonesPQ.push(A - B);
        }
        return stonesPQ.top();
    }
};