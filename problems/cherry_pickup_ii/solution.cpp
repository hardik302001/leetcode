// also see: https://leetcode.com/problems/cherry-pickup/
/*


Let MM be the number of rows in grid and NN be the number of columns in grid.

Time Complexity: (MN^2), since our helper function have three variables as input, which have MM, NN, and NN possible values respectively. In the worst case, we have to calculate them all once, so that would cost (MN^2). Also, since we save the results after calculating, we would not have repeated calculation.

Space Complexity: \mathcal{O}(MN^2)O(MN 
2
 ), since our helper function have three variables as input, and they have MM, NN, and NN possible values respectively. We need a map with size of \mathcal{O}(M \cdot N \cdot N) = \mathcal{O}(MN^2)O(M⋅N⋅N)=O(MN 
2
 ) to store the results.


*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        // different starting position as from cherry pickup
        return max(0,cherry_picker(grid,dp,0,0,m-1,n,m));
        
    }
    
    
    // here for both simulation we will have same row
    int cherry_picker(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int r,int c1,int c2,int n, int m)
    {
        
        if(c1>=m || c2>=m|| c1<0 || c2<0)
            return INT_MIN;
        if(dp[r][c1][c2]!=-1)//if we have already calculated the value for current state then return that value
            return dp[r][c1][c2];
        //if we are right most bottom corner then simply return grid value
    

        //ans will be the ans for current state + future state
        
        int ans = 0;
        
        if(c1==c2){
            ans = ans + grid[r][c1];
        }
        else{
            ans = ans + grid[r][c1]  + grid[r][c2];
        }
        
       if(r==(n-1)){
            return ans;
        }
        
        
        int temp = max({cherry_picker(grid,dp,r+1,c1-1,c2-1,n,m),cherry_picker(grid,dp,r+1,c1,c2-1,n,m), cherry_picker(grid,dp,r+1,c1+1,c2-1,n,m),
                        cherry_picker(grid,dp,r+1,c1-1,c2,n,m),cherry_picker(grid,dp,r+1,c1,c2,n,m), cherry_picker(grid,dp,r+1,c1+1,c2,n,m),
                        cherry_picker(grid,dp,r+1,c1-1,c2+1,n,m),cherry_picker(grid,dp,r+1,c1,c2+1,n,m), cherry_picker(grid,dp,r+1,c1+1,c2+1,n,m)});
        ans += temp;//add it to the ans
        dp[r][c1][c2] = ans;//memorise the answer
        return ans;
    }
        
};

