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
        cout<<size;
        int loc = size-n;
        if(loc==0){
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