// exactly same as: https://leetcode.com/problems/spiral-matrix/


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m , vector<int>(n ,-1));
        
        if (head==NULL) return ans;

        int x0 = 0, x1 = m - 1; // vertical
        int y0 = 0, y1 = n - 1; // horizon
        
        while(x0 <= x1 and y0 <= y1 and head) {    
            // travel right side
            for (int j = y0; j <= y1 and head; ++j){
                ans[x0][j] = head->val;
                head = head->next;
            }
            x0++;
            
            // travel down side
            for (int i = x0; i <= x1 and head; ++i){
                ans[i][y1] = head->val;
                head = head->next;
            }
            y1--;
            
            if (x0 > x1) break;
            // travel left side
            for (int j = y1; j >= y0 and head; --j) {
                ans[x1][j] = head->val;
                head = head->next;
            }
            x1--;
            
            if (y0 > y1) break;
            // travel up side
            for (int i = x1; i >= x0 and head; --i){
                ans[i][y0] = head->val;
                head = head->next;
            }
            y0++;
        }

        return ans;  
        
    }
};