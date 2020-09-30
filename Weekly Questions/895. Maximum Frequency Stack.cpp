// Question Link ---> https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
private:
    stack<int> elemStack, tempStack;
    unordered_map<int, int> elemFreq; // {element, frequency}
    map<int, unordered_set<int>, greater<int>> freqElemSetMap; // {frequency, set{elements}} 
public:
    FreqStack() {}
    void push(int x) {
        elemStack.push(x);
        elemFreq[x]++;
        freqElemSetMap[elemFreq[x]].insert(x);
        // Remove the element from the prev set if it does exist
        if (freqElemSetMap.count(elemFreq[x] - 1) > 0) {
            freqElemSetMap[elemFreq[x] - 1].erase(x);
            // Remove the map record if set is empty
            if (freqElemSetMap[elemFreq[x] - 1].size() == 0) {
                freqElemSetMap.erase(elemFreq[x] - 1);
            }
        }
    }
    
    int pop() {
        int topCurrentElem;
        while (!elemStack.empty()) {
            topCurrentElem = elemStack.top();
            elemStack.pop();
            int numOfCurElem = (freqElemSetMap.begin()->second).count(topCurrentElem);
            if (numOfCurElem > 0) {
                elemFreq[topCurrentElem]--;
                if (elemFreq[topCurrentElem] == 0) {
                    elemFreq.erase(topCurrentElem);
                }
                // Remove element from the set
                (freqElemSetMap.begin()->second).erase(topCurrentElem);
                // Replace current element into new set
                if (elemFreq.count(topCurrentElem) > 0) {
                    freqElemSetMap[elemFreq[topCurrentElem]].insert(topCurrentElem);
                }
                // Remove the map record if set is empty
                if ((freqElemSetMap.begin()->second).size() == 0) {
                    freqElemSetMap.erase(freqElemSetMap.begin());
                }
                break;
            }
            else {
                tempStack.push(topCurrentElem);
            }
        }
        while (!tempStack.empty()) {
            elemStack.push(tempStack.top());
            tempStack.pop();
        }
        return topCurrentElem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */