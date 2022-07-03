// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    
    int mod = 1000000007;
    int solve(int i , int j , int m , int n , vector< vector< int> > &dp, vector< vector< int> > &matrix){
        if(dp[i][j]!=-1){
            return dp[i][j];
        } 
        
        vector<int> dx = {1, 0 , -1, 0};
        vector<int> dy = {0 , 1 , 0 , -1};
        int ans = 1; // anyways , we will cosnider single element
        for(int k = 0;k<4;k++){
            int newx = i + dx[k];
            int newy = j + dy[k];
            if(newx>=0 and newx<m and newy>=0 and newy<n and matrix[i][j]<matrix[newx][newy]){
                ans  += (solve( newx, newy , m , n , dp , matrix))%mod;
            } 
        }
        
        dp[i][j] = ans%mod;
        
        return ans;
    }

    
    int countPaths(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector< vector< int> >dp(m , vector<int> (n, -1));
        
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int res = solve(i, j , m , n , dp , matrix);
                ans = (ans%mod+res%mod)%mod;
            }
        }

        return ans%mod;
    }
};