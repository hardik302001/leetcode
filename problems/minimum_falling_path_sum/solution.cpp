class Solution{
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& matrix,
             vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>m || j>n) return INT_MAX;
        if(i == m) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int temp = INT_MAX;
        temp = min(temp , solve(i+1,j-1,m,n,matrix,dp));
        temp = min(temp , solve(i+1,j,m,n,matrix,dp));
        temp = min(temp , solve(i+1,j+1,m,n,matrix,dp));
        
        return  dp[i][j] = matrix[i][j] + temp;
                
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
           ans = min(ans,solve(0,j,m-1,n-1,matrix,dp));    
        }
        return ans;
    }
    
};







// //courtesy : codencode dp series

// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
        
//         vector<vector<int> > dp(m, vector<int>(n,0));
//         for(int j = 0;j<n;j++){
//             dp[m-1][j] = mat[m-1][j];     //last row, no variation
//         }
        
//         for(int i = m-2;i>=0;i--){
//             for(int j = 0;j<n;j++){
//                 dp[i][j] = mat[i][j]; 
//                 int mini = dp[i+1][j];   // 3 chouces, so for time being kets consider middle one as minimium
//                 if(j+1<n){
//                     mini = min(mini, dp[i+1][j+1]);
//                 }
//                 if(j-1>=0){
//                     mini = min(mini, dp[i+1][j-1]);
//                 }
//                 dp[i][j] += mini;
                
//             }
//         }
        
//         int res = INT_MAX;
//         for(int j = 0;j<n;j++){
//             res = min(res, dp[0][j]);
//         }
        
//         return res;
        
//     }
// };