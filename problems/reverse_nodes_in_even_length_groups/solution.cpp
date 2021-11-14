//This is not a correct solution
//this is sid way of solving, make vector do operstions and make link list


class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        vector<int>ans;
        int n = v.size();
        int k = 1;
        int i = 0;
        
        
        //creating groups of size k
        while(n-k>=0){
            vector<int>t;
            for(int j = i;j<i+k;j++){
                t.push_back(v[j]);
            }
            if(k&1){
                ans.insert(ans.end(), t.begin(),t.end());
            }else{
                reverse(t.begin(),t.end());
                ans.insert(ans.end(), t.begin(),t.end());
            }
            i = i+k;
            n = n-k;
            k++; 
        }

        
        //extra elements left 
        vector<int>t;
        while(n--){
            t.push_back(v[v.size()-n-1]);
        }

           if(t.size()&1){ 
               ans.insert(ans.end(),t.begin(),t.end());
                
            }else{
               reverse(t.begin(),t.end());
               ans.insert(ans.end(),t.begin(),t.end());
                
            }
        
    
        //create link list
        ListNode* h = new ListNode(ans[0]);
        ListNode* header = h;
        for(int i = 1;i<ans.size();i++){
            ListNode* node = new ListNode(ans[i]);
            h->next = node;
            h = node;
        }
        

        
        return header;
    }
    
    
    
        
};