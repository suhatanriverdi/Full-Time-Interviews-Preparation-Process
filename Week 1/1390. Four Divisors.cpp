// Question Link ---> https://leetcode.com/problems/four-divisors/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res += hasFourDivisors(num);
        }
        return res;
    }
    
    int hasFourDivisors(int num) {
        int cnt = 0, sum = 0, temp;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                temp = num / i;
                if (temp == i) {
                    cnt++;
                } else {
                    cnt += 2;
                    sum += temp;
                }
                    sum += i;
            }
            if (cnt > 4) {
                return 0;
            }
        }
        return (cnt < 4 ? 0 : sum);
    }
};