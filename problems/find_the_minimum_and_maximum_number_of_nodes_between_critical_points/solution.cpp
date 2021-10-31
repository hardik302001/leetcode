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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>mx;
        int len = getCount(head);
        if (len==2){
            return {-1,-1};
        }
        
        
        //[5,3,1,2,5,1,2]
        ListNode* prev = head;
        ListNode* mid = head;
        ListNode* nex = head;
        mid = mid->next;
        nex = nex->next->next;
        
   
        int i = 1;
        while(i<(len-1)){ 
            
           // cout<<prev->val<<" "<<mid->val<<" "<<nex->val<<endl;
            if ((prev->val > mid->val) and (mid->val < nex->val)) 
                mx.push_back(i); 

            // Condition for local maxima 
            else if ((prev->val < mid->val) and (mid->val > nex->val)) 
                mx.push_back(i);
            
            
              i = i +1;
              prev = prev->next;
              mid = mid->next;
              nex = nex->next;
            
        }   
              
      
        
        if(mx.size()>=2){
            
            int mini = 100000000000;
            for(int i  = 1;i<mx.size();i++){
                int re = mx[i]-mx[i-1];
                mini = min(mini, re);
            }
              
            int maxi = mx[mx.size()-1] - mx[0];
              return{mini, maxi};
            
            
        }
        
        return {-1,-1};

            
              
        
    }
              
   
              
    
    
    int getCount(ListNode* head)
{
    // Base Case
    if (head == NULL) {
        return 0;
    }
    // Count this node plus the rest of the list
    else {
        return 1 + getCount(head->next);
    }
}
};