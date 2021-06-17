class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> elements(G.begin(), G.end());
        int result = 0;
        while(head){
            if(elements.count(head->val)){
                result++;
                while(head->next && elements.count(head->next->val)){
                   head = head->next; 
                }
            }
            head = head->next; 
        }
        return result;
    }
};