// Question Link ---> https://www.hackerrank.com/challenges/countingsort4/problem

// Complete the countSort function below.
void countSort(vector<vector<string>> arr) {
    vector<vector<string>> sorted(1000001, vector<string>());
    int size = arr.size();
    string res = "";
    for (int i = 0; i < size; i++) {
        if (i < (size / 2)) {
            arr[i][1] = "-";
        }
        sorted[stoi(arr[i][0])].push_back(arr[i][1]);
    }
    for (int i = 0; i < sorted.size(); i++) {
        for (int j = 0; j < sorted[i].size(); j++) {
            res += sorted[i][j] + " ";
        }
    }
    res.pop_back();
    cout << res;
}