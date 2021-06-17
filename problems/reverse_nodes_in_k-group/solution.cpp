
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){  //for less than k elements..return as it is..
            if(cursor == NULL) return head;
            cursor = cursor->next;
        }
        //else k ke pair mei bindass reverse karo..NULL ki chinta mat karo
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
    
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};