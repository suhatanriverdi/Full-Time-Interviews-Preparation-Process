// Question Link ---> https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 || K == 0) {
            return 0;
        }
        if (N >= 2 && K <= 2) {
            return K - 1;
        }
        return kthGrammarHelper(N, K, pow(2, N - 1), true);
    }

    int kthGrammarHelper(int N, int K, int rowSize, bool sign) {
        if (N == 1 || K == 1) {
            return !sign;
        }
        int newSize = (rowSize / 2);
        sign = (K > newSize) ? !sign : sign;
        K = ((K - newSize) > 0) ? (K - newSize) : K;
        return kthGrammarHelper(N - 1, K, newSize, sign);
    }
};