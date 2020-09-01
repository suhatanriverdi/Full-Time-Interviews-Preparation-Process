// Question Link ---> https://www.hackerrank.com/challenges/sparse-arrays/problem

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    int queriesLen = queries.size();
    vector<int> strFreq(queriesLen, 0);
    for (int i = 0; i < queriesLen; i++) {
        for (string str : strings) {
            if (queries[i] == str) {
                strFreq[i]++;
            }
        }
    }
    return strFreq;
}