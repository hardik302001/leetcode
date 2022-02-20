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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int s = 0;
        vector<int>ans;
        for(int i = 1;i<v.size();i++){
            if(v[i]==0){
                ans.push_back(s);
                s= 0;
            }else{
                s = s + v[i];
            }
        }
        
        
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