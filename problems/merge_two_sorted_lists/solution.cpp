/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        //base case
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }

        //rec vase
        ListNode* c = NULL;
        if(a->val < b->val){
            c = a;
            c->next = mergeTwoLists(a->next,b);
        }
        else{
            c = b;
            c->next = mergeTwoLists(a,b->next);
        }
        return c;
    }
};

*/

// --------------------------------------------------------------

// similar to : https://leetcode.com/problems/merge-k-sorted-lists/submissions/
class compare{
public:
    bool operator()(ListNode* &l1, ListNode* &l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        priority_queue<ListNode* , vector<ListNode*> , compare>pq;
        if(a) pq.push(a); 
        if(b) pq.push(b); 
        
        if(pq.size()==0) return NULL;
        ListNode* cur = pq.top();
        pq.pop();
        
        if(cur->next) pq.push(cur->next);
        ListNode* head = cur;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if(top->next) pq.push(top->next);
        }
        
        return head;
        
        
    }
};