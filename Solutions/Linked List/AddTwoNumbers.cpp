// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int addNodes(ListNode* l1, ListNode* l2) {
        int sum = 0;
        
        if (l1 != NULL)
            sum += l1->val;
        
        if (l2 != NULL)
            sum += l2->val;
        
        return sum;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headPlaceholder = new ListNode(0);
        ListNode* curr = headPlaceholder;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = addNodes(l1, l2) + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            if (l1 != NULL)
                l1 = l1->next;
            
            if (l2 != NULL)
                l2 = l2->next;
        }
        
        curr = headPlaceholder->next;
        delete headPlaceholder;
        return curr;
    }
};