/*
TUF
Find first mid..move one step ahead
reverse from there..


take 2 pointers one at head
other at the current pos of mid


treaverse simulatenouly until mid pointer reaches NULL
*/
class Solution {
public:
    ListNode* midpoint_first_even(ListNode* head){    //in case of even this mid function gives the first value. as mid ...out of both teh middle.
                                
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    
    
ListNode* reverseiterative(ListNode* &head){   // time : O(n) and space = O(1)
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
    
    
    
bool isPalindrome(ListNode* head) {
    if(head==NULL or head->next==NULL){
        return true;
    }

    ListNode* mid = midpoint_first_even(head);
    mid->next = reverseiterative(mid->next);
    //print(head);
    ListNode* a = head;
    ListNode* b = mid->next;
    while(b!=NULL){
        if(a->val!=b->val){
          //  cout<<"a->data "<<a->data<<endl;
          //  cout<<"b->data "<<b->data<<endl;


            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
    
    }
};