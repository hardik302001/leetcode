// very impo ques

/*
TUF
3 solutions:

1. for every eleement of first list..check if address of element of second list is same.
2. for same thing use hashmap
3. find both lengths of list.
  find(l1 - l2)
  trvaerse (l1-l2) in the list with maximum  lenghth
  now head pointers of both lists will reach at end at same..
  so if they intersect at some place..u will get to know that,,
  else return NULL..
4. traverse both lists simulatenously...as any of list ends ..replace the pointer to head of other list
   Replacing with head of other node is like doing (l1-l2) iteration in list of maximum list....so after the first cycle..both list with have same length(reach end of both lists at same time) ....
   now do second full traversal..if they are same at some point..else they reach NULL at same point..then retrurn NULL


*/


// https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL or headB==NULL){
            return NULL;
        }
        ListNode* a = headA;
        ListNode* b = headB;
        //if a and b have different len, then we will stop loop after second iteration..
        while(a!=b){
            //for the end of first iteration, we just reset the pointer to head of another linkedlist
            
            if(a==NULL){
                a = headB;
            }
            else{
                a = a ->next;
            }
            
            if(b==NULL){
                b = headA;
            }
            else{
                b = b ->next;
            }
                 
        }
        
        
        return a;    // after while loop a == b , so we are returning a
    }
};