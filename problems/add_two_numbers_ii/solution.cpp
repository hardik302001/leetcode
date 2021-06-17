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


class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode * nxt;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}
    void insertattail(ListNode* &head, int val){
        ListNode* n = new ListNode(val);
        if (head==NULL){
            head = n;
            return;
        }
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp ->next;
        }
        temp->next = n;
        n->next = NULL;

    }
    
    
    
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode* c = NULL;
        int carry = 0;

        while(l1!=NULL or l2!=NULL or carry){
            int sum = 0;
            if(l1!=NULL){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            sum = sum + carry;
            carry = sum/10;
            insertattail(c,sum%10);
        }
        
        return c;
        
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* out = NULL;
        out = addTwoNumbers1(l1,l2);
        out = reverseList(out);
        return out;
    }
};