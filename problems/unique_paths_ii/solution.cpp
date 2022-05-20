//courtesy codencode


// tabulation dp

class Solution {
public:
    long long int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        //each cell of dp array tells total no of unique ways from that cell to lat celll(mat[m-1][n-1])
        vector< vector<long long int>>dp(m,vector<long long int>(n));
        
        dp[m-1][n-1] = mat[m-1][n-1]^1;    //last cell, destination, if there is obstacle then no way to reach there, no unique path
        
        //last row        
        for(int j = n-2;j>=0;j--){
            if(mat[m-1][j]==1 or dp[m-1][j+1]==0){  //if there is obstacle, or there is no way to reach adjacent cell, then there is also no way to reach that cell, thsu dp[m-1][j] = 0; 
                dp[m-1][j] = 0;
            }
            else{
                dp[m-1][j] = 1;
            }

        }
        
         //last column      
        for(int i = m-2;i>=0;i--){
            if(mat[i][n-1]==1 or dp[i+1][n-1]==0){  //if there is obstacle, or there is no way to reach adjacent cell, then there is also no way to reach that cell, thsu dp[i][n-1] = 0; 
                dp[i][n-1] = 0;
            }
            else{
                dp[i][n-1] = 1;
            }

        }
        
        
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                if(mat[i][j]==1){    //cell have obstacle
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};




// also see: https://leetcode.com/problems/unique-paths-ii/discuss/1909942/C%2B%2B-MEMO-TABULAR-SPACE-OPTIMISED


// recur + memo dp
/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i = 0, j = 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return fun(obstacleGrid,i, j, m, n, dp);
    }
    int fun(vector<vector<int>> &obstacleGrid, int i, int j, int m, int n, vector<vector<int>> &dp) {
       if (i > m-1 || j > n-1 || obstacleGrid[i][j] == 1) return 0;
       if (i == m - 1 && j == n - 1) return 1;
	   // dp part
        if (dp[i][j] != -1) return dp[i][j];
       // Right
        int right = fun(obstacleGrid, i, j+1, m, n, dp);
        // DOWN
        int down = fun(obstacleGrid, i+1, j, m, n, dp);
        // return
        return dp[i][j] = (right + down);
    }
};
        
        
*/