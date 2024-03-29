// also see: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/


// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/1151418/Longest-Increasing-Path-in-a-Matrix-or-Short-and-Simple-w-Explanation
// dp soln with memoization easy peasy!
// TC: O(n*m)
// current posi is start of inc path

class Solution {
public:
    int solve(int i , int j , int m , int n , vector< vector< int> > &dp, vector< vector< int> > &matrix){
        if(dp[i][j]!=-1){
            return dp[i][j];
        } 
        
        vector<int> dx = {1, 0 , -1, 0};
        vector<int> dy = {0 , 1 , 0 , -1};
        int res = 1;     // path will be atleast of size 1 ( suppose all 4 directions are invalid[ 3rd sample TC] )
        for(int k = 0;k<4;k++){
            int newx = i + dx[k];
            int newy = j + dy[k];
            if(newx>=0 and newx<m and newy>=0 and newy<n and matrix[i][j]<matrix[newx][newy]){
                res = max(res, 1 + solve( newx, newy , m , n , dp , matrix));   // max of all 4 direction longest path
                
                // 1 + ...bcz we know current cell is surely included in longest inc path!
                // this is length of paths
            } 
        }
        dp[i][j] = res;
        
        return res;
    }

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector< vector< int> >dp(m , vector<int> (n, -1));
        
        int ans = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int res = solve(i, j , m , n , dp , matrix);
                ans = max(ans, res);
            }
        }

        return ans;
    }
};






/*
//BRUTE FORCE!      TLE
// tc: O(m*n*4^(m*n))

class Solution {
public:
    
    int solve(int i , int j , int m , int n , vector< vector< int> > &dp, vector< vector< int> > &matrix){
        
        vector<int> dx = {1, 0 , -1, 0};
        vector<int> dy = {0 , 1 , 0 , -1};
        int res = 1;
        for(int k = 0;k<4;k++){
            int newx = i + dx[k];
            int newy = j + dy[k];
            if(newx>=0 and newx<m and newy>=0 and newy<n and matrix[i][j]<matrix[newx][newy]){
                res = max(res, 1 + solve( newx, newy , m , n , dp , matrix));
            } 
        }
        
        return res;
    }

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector< vector< int> >dp(m , vector<int> (n, -1));
        
        int ans = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int res = solve(i, j , m , n , dp , matrix);
                // cout<<matrix[i][j] <<" "<< res<<endl;
                ans = max(ans, res);
            }
        }

        return ans;
    }
};
*/