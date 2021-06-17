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