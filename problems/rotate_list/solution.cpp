//k = k%length
//link last node to head node
//move head(n-k)times and make prev of head to null.


class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0){
            return head;
        }
        
        
        int l = 1;
        ListNode *tmp=  head;
        while(tmp->next!=NULL){
            l++;
            tmp = tmp->next;
        }
        k = k%l;//step 1
        tmp->next = head;//step2 , to make cycle
        int pos = l-k;
        
        for(int i = 0;i<pos;i++){
            tmp = tmp->next;
        }
        
        
        head = tmp->next;
        tmp->next = NULL;
        
        return head;
        
        
    }
};