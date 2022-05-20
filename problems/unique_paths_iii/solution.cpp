//DFS + BACKTRACK!
/*
Explanation:
First step, we need to know where the starting point is. We also want to know the number of empty cells.
So we iterate through the grid, count empty cells and save the starting point - start_x and start_y.
Now, we do classic DFS, marking the visited cells with -1 and counting the cells we passed.
If we reached the ending point and we passed empty number of cells - this means we passed by every non-obstacle cell.


We need to cover all non empty boxes and then recah target!

*/

/*
Time Complexity : O(3^(m * n)). At every cell (except the start cell), we can continue the path exploration in 3 direction (after excuding previous visited cell) and there can be O(m*n) cells in total to be visited. In reality, the number of recursions required is much less due to dead-ends.

Space Complexity : O(m*n) required for implicit recursive stack in dfs.
*/

class Solution {
public:
    int res = 0;
    int empty = 1; // including dest also
    
    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
        
        if (grid[x][y] == 2) {
            if(empty == count) res++; 
            return;
        }
        
        //so now we are at grid[x][y] = 0
        
        grid[x][y] = -1;  // mark as visited
        
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        
        
        grid[x][y] = 0;          //backtrack, mark all again grid[x][y] = 0, from -1
        
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x, start_y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) start_x = i, start_y = j;
                else if (grid[i][j] == 0) empty++;
            }
        }
        
        dfs(grid, start_x, start_y, 0);
        return res;
    }
};