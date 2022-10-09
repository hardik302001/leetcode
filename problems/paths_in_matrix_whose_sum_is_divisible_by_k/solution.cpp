// 3d dp
// i , j , ( sum till mat[i][j] from (0 , 0) )%k

   

class Solution {
public:
    // use vetor, array giving MLE
    vector<vector<vector<int>>> dp;

    const long long mod = 1e9 + 7;
    int recur(int x, int y, int s , int n , int m , int k, vector<vector<int>>& grid){
        if(x>=n or y>=m) return 0;
        
        s = s + grid[x][y];
        s = s%k;
        
        if(x==n-1 and y==m-1) return ( s==0 );
        
        if(dp[x][y][s]!=-1) return dp[x][y][s]%mod;
        
        return dp[x][y][s] = (recur(x+1, y , s , n , m , k , grid)%mod + recur(x , y+1, s, n , m , k, grid)%mod)%mod;
              
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));

        return recur(0 , 0 , 0 , n , m , k , grid);     
    }
};