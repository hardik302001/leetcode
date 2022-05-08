/* RECURSION */

// class Solution {
// public:
//     bool hasValidPath(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         if((m+n-1)&1) return false;
        
//         int req = (m+n-1)/2;
        
//         return recur(grid , m , n , 0 , 0, 0 , 0 , req);
        
//     }
    
//     bool recur(vector<vector<char>>& grid , int m , int n  , int i , int j , int open , int closed , int req){
//         if(i>=m or j>=n) return false;
        
//         if(grid[i][j]=='('){
//             open++;
//         }else{
//             closed++;
//         }
//         if (closed>open or open>req){
//             return false;
//         }
//         if(i==m-1 and j==n-1){
//             if(open==req and closed==req){
//                 return true;
//             }
//         }
        
//         bool ans = recur(grid , m , n , i+1 , j , open , closed , req) or recur(grid , m , n , i , j+1 , open , closed , req);
        
//         return ans;
        
        
//     }
// };



/* DP 3 state 4 variable */

// class Solution {
//         int dp[105][105][205];
// public:
    
//     bool hasValidPath(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         if((m+n-1)&1) return false;
        
//         int req = (m+n-1)/2;
//         memset(dp , -1 , sizeof dp);
//         return recur(grid , m , n , 0 , 0, 0 , 0 , req);
        
//     }
    
//     bool recur(vector<vector<char>>& grid , int m , int n  , int i , int j , int open , int closed , int req){
//         if(i>=m or j>=n) return false;

        
//         if(grid[i][j]=='('){
//             open++;
//         }else{
//             closed++;
//         }
//         if (closed>open or open>req){
//             return false;
//         }
//         if(i==m-1 and j==n-1){
//             if(open==req and closed==req){
//                 return  dp[i][j][open] = true;
//             }
//         }
//         if(dp[i][j][open]!=-1){
//             return dp[i][j][open];
//         }
//         if(recur(grid , m , n , i+1 , j , open , closed , req)) return dp[i][j][open] = true;
//         if(recur(grid , m , n , i , j+1 , open , closed , req)) return dp[i][j][open] = true;

//         return  dp[i][j][open] = false;
        
        
//     }
// };


/* DP 3 STATE 3 VARIABLE.. */

class Solution {
        int dp[105][105][205];
public:
    
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if((m+n-1)&1) return false;
        
        int req = (m+n-1)/2;
        memset(dp , -1 , sizeof dp);
        return recur(grid , m , n , 0 , 0, 0 , req);
        
    }
    
    bool recur(vector<vector<char>>& grid , int m , int n  , int i , int j , int open , int req){
        if(i>=m or j>=n or open<0) return false;
 
        
        if(grid[i][j]=='('){
            open++;
        }else{
            open--;
        }
        if (open<0 or open>req){
            return false;
        }
        if(i==m-1 and j==n-1){
            if(open==0){
                return  dp[i][j][open] = true;
            }
        }
        if(dp[i][j][open]!=-1){
            return dp[i][j][open];
        }
        if(recur(grid , m , n , i+1 , j , open ,  req)) return dp[i][j][open] = true;
        if(recur(grid , m , n , i , j+1 , open ,  req)) return dp[i][j][open] = true;
        
        return  dp[i][j][open] = false;
        
        
    }
};