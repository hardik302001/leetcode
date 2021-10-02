//courtesy : codencode yt dp series, logic, the code is written by me.
//see prev code(first one) also.

//also see DUNGEOUN GAME :https://leetcode.com/problems/dungeon-game/submissions/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp(m+1, vector<int> (n+1,INT_MAX));
    
    
        dp[m][n-1] = 0;
        dp[m-1][n] = 0;
        

        
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        
        return dp[0][0];
        
    }
};