

/*
take starting 2 lists from vector..merge them and push at end ...

do thsi until you have only on list left in the vector
 tc : O(nlogk)
 sc: O(1)


*/
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
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0){
            return NULL;
        }
        
        while(lists.size()>1){
            ListNode* combine = merge2Lists(lists[lists.size() -1], lists[lists.size() - 2]);
            lists.pop_back();
            lists.pop_back();
            lists.push_back(combine);
        }
        
        return lists[0];
    }
    
    
    ListNode* merge2Lists(ListNode* l1 , ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        
        if(l2==NULL){
            return l1;
        }
        
        ListNode* c = NULL;
        if(l1->val>l2->val){
            c = l2;
            c->next = merge2Lists(l1, l2->next);
        }
        else{
            c = l1;
            c->next = merge2Lists(l1->next, l2);
        }
        return c;
    }
    
    
};





// check my c++ solution, without using push_back, erase, which is time consuming,
// use only 34ms
/*
class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};

*/



/*


class Solution {
public:

    
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
    
    ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for(auto l : lists) {
            if(l)  q.push(l);    //adress of head pointer
        }
        if(q.empty())  return NULL;

        ListNode* result = q.top();
        q.pop();
        
        if(result->next) q.push(result->next);   //next of head
        
        ListNode* tail = result;            
        while(!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return result;
    }
};

*/