// Question Link ---> https://www.hackerrank.com/challenges/recursive-digit-sum/problem

long long int getDigitSum(string n) {
    long long int sum = 0;
    for (char num : n) {
        sum += num - '0';
    }
    return sum;
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
    long long int sum = 0;
    for (char num : n) {
        sum += num - '0';
    }
    sum *= k;
    while (sum > 10) {
        sum = getDigitSum(to_string(sum));
    }
    return sum;
}