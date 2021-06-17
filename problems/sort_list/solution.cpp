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
    
ListNode* merge(ListNode*a, ListNode*b){         //merge 2 sorted link list time = O(m+n), space = O(m+n)
//2 pointer
//find min and append it to a third link list c

//base vase
if(a==NULL){
    return b;
}
if(b==NULL){
    return a;
}

//rec vase
ListNode* c=NULL;
if(a->val < b->val){
    c = a;
    c->next = merge(a->next,b);
}
else{
    c = b;
    c->next = merge(a,b->next);
}
return c;

}



ListNode* midpoint_first_even(ListNode* head){    //in case of even this mid function gives the first value. as mid ...out of both teh middle.
                                
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}



    
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next ==NULL){
        return head;
    }
    //rec case
    ListNode* mid = midpoint_first_even(head); //you cant use here midpoint_second_even bcz when length is 2, the case goes into infinite loop ...always taking min,,tak eth eifrst middle..
   // cout<<"mid = "<<mid->data<<endl;

    //break at mid
    //and divide it in 2 part
    ListNode* x = head;
    ListNode* y = mid->next;
    mid->next = NULL;

    //recursive sort
    x = sortList(x);
    y = sortList(y);
    return merge(x,y);

    }
};