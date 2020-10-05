// Question Link ---> https://www.hackerrank.com/challenges/jesse-and-cookies/problem

int cookies(int k, vector<int> A) {
    int size = A.size(), result = 0;
    priority_queue<int, vector<int>, greater<int>> priorityQueue;
    for (int i = 0; i < size; i++) {
        priorityQueue.push(A[i]);
    }

    while (priorityQueue.size() > 1 && priorityQueue.top() < k) {
        int firstLeast = priorityQueue.top();
        priorityQueue.pop();
        int secondLeast = priorityQueue.top();
        priorityQueue.pop();
        int tempSum = firstLeast + (secondLeast * 2);
        priorityQueue.push(tempSum);
        result++;
    }

    if (priorityQueue.size() >= 1 && priorityQueue.top() < k) {
        return -1;
    }
    
    return result;
}