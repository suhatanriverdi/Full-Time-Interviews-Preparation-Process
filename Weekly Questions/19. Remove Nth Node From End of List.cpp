// Question Link ---> https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0, stepsToTake = 0;
        ListNode *dummy = new ListNode(0, head); // dummy -> head -> ...
        ListNode *walk = head, *start = dummy, *temp = NULL;
        while (walk) {
            len++;
            walk = walk->next;
        }
        stepsToTake = len - n;
        while (start && stepsToTake--) {
            start = start->next;
        }
        temp = start->next;
        start->next = start->next->next;
        delete(temp);
        return dummy->next;
    }
};