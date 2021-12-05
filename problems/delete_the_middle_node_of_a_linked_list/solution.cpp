// 2pointer, rabbit tortoise



class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        if(head->next == NULL)
            return NULL;
        while(second!= NULL && second->next!= NULL){
            first = first->next;
            second = second->next->next;
        }
        ListNode* temp = head;
        while(temp->next!=first){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};