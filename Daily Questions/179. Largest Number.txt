// QUESTION LINK ---> https://leetcode.com/problems/largest-number

First Solution (12-16 ms)
Here, we basically do the first thing that comes to our minds, first we convert each integer to string, then we sort them by creating custom comparator. The trick here is that;

(a+b) < (b+a)
Assume that a = 97, b = 978
We check which is greater;
a+b = 97978 > b+a= 97897

So, this trick does the job but there is also one edge case, the trailing zeros 000...
if res contains only zeros such as res = "000" meaning that we can basically check the first digit of res, if it is zero then we return zero, because there is no possibility that the digits greater than zero comes after the first zero

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        string res = "";
        vector<string> strNums(size, "");
        for (int i = 0; i < size; i++) {
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            return ((a+b) > (b+a));
        });
        
        for (auto num : strNums) {
            res += num;
        }
        
        return res[0] == '0' ? "0" : res;
    }
};

Second Solution (8 ms)
Here, this time, we are aware of optimization of the custom comparator, right?, we know that we can start checking the digits of each string one by one starting from the left side, in this way we can recognize which one is greater earlier; What I mean is, just consider this case;

Given that a = 123456789, b = 987654321

This operation "(a+b) > (b+a)", checking this concatenation of two strings will take much more time than checking only first digits (a[i] > b[i])
So this is the core trick/optimization here :)

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        string res = "";
        vector<string> strNums(size, "");
        for (int i = 0; i < size; i++) {
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            int len = min(a.size(), b.size());
            for (int i = 0; i < len; i++) {
                if (a[i] != b[i]) {
                    return (a[i] > b[i]);
                }
            }
            return ((a+b) > (b+a));
        });
        
        for (auto num : strNums) {
            res += num;
        }
        
        return res[0] == '0' ? "0" : res;
    }
};

Third and The BEST Solution (4 ms)
Runtime: 4 ms, faster than 99.91% of C++ online submissions

Here, lastly, we realized that we can also check our result string "res" inside of the loop! Because the result string which has trailing zeros may appear much earlier than until we finish the loop

if (res[0] == '0') {
	return "0";
}

we don't have to wait till the end, so we just add code snippet above

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        string res = "";
        vector<string> strNums(size, "");
        for (int i = 0; i < size; i++) {
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            int len = min(a.size(), b.size());
            for (int i = 0; i < len; i++) {
                if (a[i] != b[i]) {
                    return (a[i] > b[i]);
                }
            }
            return ((a+b) > (b+a));
        });
        
        for (auto num : strNums) {
            res += num;
            if (res[0] == '0') {
                return "0";
            }
        }
        
        return res;
    }
};