//DP SOLUTION: SEE shivank goel :https://www.youtube.com/watch?v=q3-6jaNvj6c&t=509s for more info 
// also see happy coding video on yt
/*
    So the idea here is instead of doing 1 traversal form (0,0)->(n-1,n-1) and then 1 traversal from (n-1,n-1)->(0,0)
    We will do 2 traversals independtly from (0,0)->(n-1,n-1). Now lets's talk about state we can have 
[r1,c1,r2,c2] -> state we can have but this is O(n^4) we can reduce it to O(n^3) because manhattan distance remains same
i.e. (r1-0) + (c1-0) = (r2-0) + (c2-0) so the current state becomes [r1,c1,c2] and r2 = r1+c1-c2 
*/

// TC: O(n3)
// SC = O(n3)
 
// we kept c2 in terms of r1, c1, r2 because to keep one varible less! To improve complexity

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,cherry_picker(grid,dp,0,0,0,n));
    }
    
    int cherry_picker(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int r1,int c1,int c2,int n)
    {
        int r2 = r1 + c1 - c2;//explanation in the above section 
        //if any of the current rows or colums goes out of bound or there is a thorn on a current block then return INT_MIN
        if(r1>=n || r2>=n || c1>=n || c2>=n|| grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)//if we have already calculated the value for current state then return that value
            return dp[r1][c1][c2];
        //if we are right most bottom corner then simply return grid value

        int ans = 0;
        
        if(r1== r2 and c1==c2){
            ans = ans + grid[r1][c1];
        }
        else{
            ans = ans + grid[r1][c1]  + grid[r2][c2];
        }
        
        if(r1==n-1 && c1 == n-1)
            return ans;  //bcz if r1 and c1==(n-1)(n-1) then, r2 and c2 will also be eqaul to (n-1)(n-1), so basically same cell
        
        
        //ans will be the ans for current state + future state
        
        
        //Now we need to take the max of 4 cases for both traversals
        //1.) Right Right
        //2.) Down Down
        //3.) Right Down
        //4.) Down Right
        int temp = max({cherry_picker(grid,dp,r1,c1+1,c2+1,n),cherry_picker(grid,dp,r1+1,c1,c2,n),
                       cherry_picker(grid,dp,r1,c1+1,c2,n),cherry_picker(grid,dp,r1+1,c1,c2+1,n)});
        ans += temp;//add it to the ans
        dp[r1][c1][c2] = ans;//memorise the answer
        return ans;
    }
        
};




/*
//backtracking soliton O(4^(n*n))
//TLE (but still it is brute force solution! for interview pov)
// for more info visit pepcoding video for the same ques

//we wont go 2 times, up to dowm (find max cherry), down to top (find max cherry) and do sum!   <= THIS IS WRONG, greedy solution wont work ! see pepcoding video

class Solution {
public:
    int m = 0;
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
            return grid[0][0];
        }
        toptodown(n , grid, 0 , 0, 0);
        return m;
    }
    
    void toptodown(int n , vector<vector<int>>& grid, int i , int j, int cherrycount){
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==-1){
            return;
        }
        if(i==n-1 and j==n-1){
            downtotop(n, grid, n-1, n-1, cherrycount);
        }
        
        int cherry = grid[i][j];
        grid[i][j] = 0;
        // do all dfs stuff and then backtrack
        toptodown(n, grid, i+1, j, cherrycount + cherry);
        toptodown(n, grid, i, j+1, cherrycount + cherry);
        
        grid[i][j] = cherry; //backtracking
        
    }
    
    void downtotop(int n , vector<vector<int>>& grid, int i , int j, int cherrycount){
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==-1){
            return;
        }
        if(i==0 and j==0){
            m = max(m , cherrycount);
            return;
        }
        
        int cherry = grid[i][j];
        grid[i][j] = 0;
        
        downtotop(n, grid, i-1, j, cherrycount + cherry);
        downtotop(n, grid, i, j-1, cherrycount + cherry);
        
        grid[i][j] = cherry; //backtracking
        
    }
};

*/



