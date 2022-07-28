// without finding length
// optimised
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<pair<int, int>>s;  // ind , val
        int i = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            while(s.size() and s.top().second < cur->val){
                ans[s.top().first] = cur->val;
                s.pop();   
            }
            s.push({i , cur->val});
            cur = cur->next;     
            ans.push_back(0);
            i++;
        }
        return ans;        
    }
};


// -------------------------------------------------------------------------------------

// calculate length and make a predefined length array, and do basic nge
/*
class Solution {
public:
    
    int len(ListNode* head){
        ListNode* tmp = head;
        int l = 0;
        while(tmp!=NULL){
            l++;
            tmp = tmp->next;
        }
        return l;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        int n = len(head);
        vector<int>ans(n , 0);
        stack<pair<int, int>>s;  // ind , val
        
        ListNode* cur = head;
        for(int i = 0;i<n;i++){
            while(s.size() and s.top().second < cur->val){
                ans[s.top().first] = cur->val;
                s.pop();   
            }
            s.push({i , cur->val});
            cur = cur->next;     
        }
        return ans;        
    }
};

*/