class Solution {
private:
    int sum = 0;
    
    int helper(ListNode* node) {
        if(!node) return 1;
        
        node->val += helper(node->next);
        int carry = node->val/10;
        node->val = node->val%10;
        return carry;
    }
    
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        helper(dummy);
        return dummy->val ? dummy : dummy->next;
    }
};