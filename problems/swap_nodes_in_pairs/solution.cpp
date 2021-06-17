/*
       #---->@---->@---->@---->@---->@---->@
                   ^     ^
                   pre   cur

      1. pre->next = cur->next
                    __________
                   /          \
       #---->@---->@     @---->@---->@---->@
                   ^     ^
                   pre   cur

      2. pre = pre->next
                    __________
                   /          \
      #---->@---->@      @---->@---->@---->@
                         ^     ^
                         cur   pre

      3. cur->next = pre->next
                    __________
                   /          \
       #---->@---->@     @     @---->@---->@
                          \_________/
                         ^     ^
                         cur   pre

      4. pre->next = cur
                   __________
                  /          \
      #---->@---->@     @<----@     @---->@
                         \_________/
                        ^     ^
                        cur   pre
    
      5. pre = cur; cur = cur->next
                   __________
                  /          \
      #---->@---->@     @<----@     @---->@
                         \_________/
                        ^           ^
                        pre         cur
 */


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode* tmp = new ListNode(); //initial node 
        tmp->next = head; //tmp pointing to head..and we know that after full swapping our head node will be head->next... 1 2 3 4
        //            2 1 4 3
        //so newhead is 2..that is head->next
        ListNode *pre = tmp, *cur = head;
        while(cur && cur->next){
            pre->next = cur->next;
            pre = pre->next;           //bring pre 2 step front
            cur->next = pre->next;
            pre->next = cur;           //chnage direction
            pre = cur;                 // bring pre 1 step back to cur position
            cur = cur->next;          //bring cur 2 step ahead
        }
        return tmp->next;
    }
};