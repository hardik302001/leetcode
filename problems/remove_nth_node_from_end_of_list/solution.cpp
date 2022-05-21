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


// 1 traversal


// removing nth from end == removing (total length - n) from beginning

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode(); // extra node to reach one step before the node to be removed
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        // now slow will move (length - n) steps from beginning
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        
        // remove the node
        slow->next = slow->next->next;
        
        return start->next;
    }
};



// 2 traverals
/*
class Solution {
public:
    int length(ListNode* head){
        int cnt = 1;
        while(head->next!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = length(head);
        int loc = size-n;  // remove after loc elements ( or loc -1 jumps bcz head points to 1st element)
        if(loc==0){ // remove first element
            head = head->next;
            return head;
        }
        ListNode* temp = head;
        for(int jump = 1;jump<=(loc-1);jump++){
            temp = temp->next;
        }
        ListNode* actual = temp->next;
        
        temp->next = actual->next;
        actual->next = NULL;
        
        return head;
    
    }
};
*/