 // EXACTLY SAME AS:  https://leetcode.com/problems/range-sum-query-2d-immutable/

// keep r1 , c1 as i-k , j-k
// keep r2 , c2 as i + k + 1 , j + k + 1


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>>dp = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        
        for(int i = 1;i<=row;i++){
            for(int j = 1;j<=col;j++){
                dp[i][j] = mat[i-1][j-1]+dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        
        for(int i = 0; i<row;i++){
            for(int j = 0;j<col;j++){
                mat[i][j] = dp[min(row , i+k+1)][min(col , j + k +1)] + dp[max(i-k, 0)][max(j-k, 0)] - dp[max(i-k, 0)][min(j+k+1 , col)] - dp[min(i+k+1, row)][max(j-k,0)] ;
            }
        }
        
        return mat;
        
    }
};