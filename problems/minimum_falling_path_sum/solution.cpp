//courtesy : codencode dp series

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n,0));
        for(int j = 0;j<n;j++){
            dp[m-1][j] = mat[m-1][j];     //last row, no variation
        }
        
        for(int i = m-2;i>=0;i--){
            for(int j = 0;j<n;j++){
                dp[i][j] = mat[i][j]; 
                int mini = dp[i+1][j];   // 3 chouces, so for time being kets consider middle one as minimium
                if(j+1<n){
                    mini = min(mini, dp[i+1][j+1]);
                }
                if(j-1>=0){
                    mini = min(mini, dp[i+1][j-1]);
                }
                dp[i][j] += mini;
                
            }
        }
        
        int res = INT_MAX;
        for(int j = 0;j<n;j++){
            res = min(res, dp[0][j]);
        }
        
        return res;
        
    }
};