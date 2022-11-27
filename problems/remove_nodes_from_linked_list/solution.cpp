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
    ListNode* removeNodes(ListNode* head) {
        vector<int>v;
                

        int p = -1;
        while(head){
            v.push_back(head->val);
            head = head->next;
        
        }

        int n = v.size();
        // nge stack
        vector<int>ans;
        stack<int>s;
        
        for(int i = 0;i<n;i++)
        {
            while(!s.empty() and s.top()<v[i]){
                s.pop();
            }
            s.push(v[i]);
        }        

        while(s.size()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        int size = ans.size();
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