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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller_ptr = new ListNode(0), *greater_ptr = new ListNode(0), *ptr = head;
        ListNode *smaller = smaller_ptr, *greater = greater_ptr;
        
        while (ptr) {
            if (ptr->val < x) {
                smaller_ptr->next = ptr;
                smaller_ptr = smaller_ptr->next;
            }
            
            else {
                greater_ptr->next = ptr;
                greater_ptr = greater_ptr->next;
            }
            ptr = ptr->next;
        }
        
        greater_ptr->next = NULL;
        smaller_ptr->next = greater->next;
        return smaller->next;
    }
};

// TC : O(N) , one traversal
// SC : O(1),bcz  we are just chnaging pointers