// Question Link ---> https://leetcode.com/problems/search-insert-position/

// Recursive Solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
    
    int binarySearch(vector<int> &nums, int L, int R, int &target) {
        int mid = (L + R) / 2;
        if (L <= R) {
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                return binarySearch(nums, mid + 1, R, target);
            }
            return binarySearch(nums, L, mid - 1, target);
        }
        return (target > nums[mid]) ? mid + 1 : mid;
    }
};

// Iteravite Solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
    
    int binarySearch(vector<int> &nums, int L, int R, int &target) {
        int mid = 0;
        while (L <= R) {
            mid = (L + R) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[mid]) {
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        return (target > nums[mid]) ? mid + 1 : mid;
    }
};