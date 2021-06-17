class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *first=head;
        while(first!=NULL && first->next!=NULL){
            if(first->val==first->next->val){
                first->next=first->next->next;
            }else{
                first=first->next;
            }
        }
        return head;
    }
};