// https://www.youtube.com/watch?v=R6-PnHODewY

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);  // dummy nodes pointing to head!
        // so we return dummy->next as the new head of updated list
        dummy->next = head;
        
        ListNode* cur = dummy;
        while (head!=NULL) {
            if (head->next!=NULL and head->val == head->next->val) {
                // skip nodes whose values are equal to head!
                
                while (head->next!=NULL and head->val == head->next->val) {
                    head = head->next;
                }
                cur->next = head->next;
            }
            else {
                cur = cur->next;
            }
            
            head = head->next;
        }
        return dummy->next;
    }
};