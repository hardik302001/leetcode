class Solution {
public:
    bool dfs(int i , int j , vector<vector<int>>&grid){   // if we can reach end
        int m = grid.size();
        int n = grid[0].size();
        if(i==m-1 and j==n-1) return true;  // reach end
        if(i<0 or i>=m or j<0 or j>=n) return false;
        
        if(grid[i][j]==1){
            grid[i][j]=0;
            return dfs(i+1, j, grid) or dfs(i , j+1 , grid);
        }else{
            return false;
        }
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // explore a path and mark all visited node as 0
        dfs(0 , 0, grid);
        
        
        // update first and last for next dfs(bcz they were marked 0 after first dfs)
        grid[0][0] = 1 ;
        grid[m-1][n-1] = 1;
        
        // if we can again reach end , it means we have more than one path, so we cant block it,
        // else we can block it, thus return not(if we can reach end)
        return !dfs(0 , 0, grid);
    }
};