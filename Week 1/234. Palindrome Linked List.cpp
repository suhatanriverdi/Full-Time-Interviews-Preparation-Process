// Question Link ---> https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Solution 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *walk = head;
        vector<string> toBeChecked;
        while (walk) {
            toBeChecked.push_back(to_string(walk->val));
            walk = walk->next;
        }
        return isReallyPalindrome(toBeChecked);
    }
    
    bool isReallyPalindrome(vector<string> &str) {
        int size = str.size();
        for (int left = 0, right = size - 1; left < size; left++, right--) {
            if (str[left] != str[right]) {
                return false;
            }
        }
        return true;
    }
};

// Solution 2 (Better)
class Solution {
public:
	string normal, reverse;
    bool isPalindrome(ListNode* head) {
        goNormal(head);
        goReverse(head);
        return (normal == reverse);
    }
    
    void goNormal(ListNode* current) {
    	if(!current) return;
    	normal.push_back(current->val);
    	goNormal(current->next);
	}
    
    void goReverse(ListNode* current) {
    	if(!current) return;
    	goReverse(current->next);
    	reverse.push_back(current->val);
	}
};

// Solution 3 (Much Better)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
	    string res;
        traverse(head, res);
        int size = res.size();
        for (int left = 0, right = size - 1; left < size; left++, right--) {
            if (res[left] != res[right]) {
                return false;
            }
        }
        return true;
    }
    
    void traverse(ListNode* current, string &res) {
    	if (!current) {
            return;
        }
    	res.push_back(current->val);
    	traverse(current->next, res);
	}
};