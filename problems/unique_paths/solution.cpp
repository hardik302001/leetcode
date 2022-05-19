// The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.

// Space Complexity: As we are using extra space for the dummy matrix the space complexity will also be O(n*m).

// recursive 

class Solution {
public:

    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return countPaths(0,0,m,n,dp);
    }
};

/*


// tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int>>dp(m,vector<int>(n));
        for(int i = 0;i<m;i++){
            dp[i][n-1] = 1;
        }
        for(int j = 0;j<n;j++){
            dp[m-1][j] = 1;
        }
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[i][j]= dp[i+1][j] + dp[i][j+1];
            }
        }    
        return dp[0][0];
    }
};

*/