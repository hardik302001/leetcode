
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return max(0,cherry_picker(grid,dp,0,0,m-1,n,m));
    }
    
    int cherry_picker(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int r,int c1,int c2,int n, int m)
    {
        
        //if any of the current rows or colums goes out of bound or there is a thorn on a current block then return INT_MIN
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

