class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(res,helper(grid,0,i,m,n,moveCost,dp));
        }
        return res;
    }
    
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& moveCost, vector<vector<int>> &dp){
        if(i==m-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int minimum = INT_MAX;
        for(int k=0;k<n;k++){
            int temp = grid[i][j] + moveCost[grid[i][j]][k] + helper(grid,i+1,k,m,n,moveCost,dp);
            minimum = min(minimum,temp);
        }
        return dp[i][j] = minimum;
    }
};