/*
Iterate through each row and column one by one, for each i (row) and j (column) pick the minimum element between rowSum[i] and colSum[j] and assign el = min(rowSum[i], colSum[j]) and reduce this el from both sum entries respectively.


Time Complexity : O(n*m)
Space Complexity: O(n*m) aux space : O(1)

*/


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        int rows = rs.size();
        int cols = cs.size();
        int req;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                req = min(rs[i], cs[j]);
                ans[i][j] = req;
                rs[i] -= req;
                cs[j] -= req;
            }
        }
        return ans;
    }
};