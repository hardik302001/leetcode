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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c = new ListNode();  // dummy node with initial value 0
        ListNode *temp = c; // temp pointing to head of c
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
            
            ListNode* node = new ListNode(sum%10);
            c->next = node;
            c = c->next;
        }
        
        return temp->next;   // answer starts from next of head of c    
        
    }
};

/*

Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.

*/