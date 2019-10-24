// 206 - Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextPlaceholder = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPlaceholder;
        }

        return prev;
    }
};