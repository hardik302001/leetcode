/*
take starting 2 lists from vector..merg ethem and push at end ...

do thsi until you have only on list left in the vector



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
    
    
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
}
    
};