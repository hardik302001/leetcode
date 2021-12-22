/*
split in 2 parts
reverse second part

change links simulatenuosly
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next==NULL)
            return;
        ListNode* slow=head, *fast=head;
        ListNode* head2;
        while (fast && fast->next) {
            fast=fast->next->next;
            slow=slow->next;
        }
        head2=reverse (slow->next);
        slow->next=NULL;               //break the first list  
                                       //same as we did in mergesort
        merge (head, head2);
    }
    ListNode *reverse (ListNode*head) {
        if (!head || !head->next) return head;
        ListNode* ans=reverse (head->next);
        head->next->next=head;
        head->next=NULL;
        return ans;
    }
    void merge (ListNode* first, ListNode* second) {  // iterative merge
        while (second) {
            ListNode* firstNext=first->next;
            ListNode* secondNext=second->next;
            first->next=second;
            second->next=firstNext;
            second=secondNext;
            first=firstNext;
        }
    }
};
