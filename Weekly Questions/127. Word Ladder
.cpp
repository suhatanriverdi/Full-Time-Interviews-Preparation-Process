// Question Link ---> https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()), visited;
        int result = 0, wordSize = beginWord.size();
        if (wordSet.find(endWord) == wordSet.end()) {
            return result;
        }
        queue<pair<string, int>> wordsQueue; // {word, stepsTaken}
        wordsQueue.push({beginWord, 1});
        while (!wordsQueue.empty()) {
            pair<string, int> cur = wordsQueue.front();
            wordsQueue.pop();
            if (cur.first == endWord) {
                return cur.second;
            }
            string originalWord = cur.first;
            for (char &eachLetter : cur.first) {
                for (char c = 'a'; c <= 'z'; c++) {
                    eachLetter = c;
                    if (wordSet.find(cur.first) != wordSet.end() && visited.find(cur.first) == visited.end()) {
                        wordsQueue.push({cur.first, cur.second + 1});
                        visited.insert(cur.first);
                    }
                }
                cur.first = originalWord;
            }
        }
        return 0;
    }
};