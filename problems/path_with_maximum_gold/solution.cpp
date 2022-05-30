// backtracking 
// TC: O(4^(m*n))

class Solution {
public:
    vector<int>dx = {1, 0 , -1 , 0};
    vector<int>dy = {0, 1 , 0 , -1};
    
    int dfs(vector<vector<int>>& grid, int x , int y , int m , int n){
        int ans = grid[x][y];   // considering current elmeent as answer(supoose we are at dead end corner , we cant consider any more adjacent elements , so we only conisder curent element)
        
        int temp = grid[x][y];
        
        grid[x][y] = 0;
        
        for(int i = 0;i<4;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx>=0 and newx<m and newy>=0 and newy<n and grid[newx][newy]!=0){
                ans = max ( ans , temp + dfs(grid , newx, newy, m , n));  // temp + bcz next stage with current position value
            }
        }
        
        grid[x][y] = temp;

        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]!=0){
                    int ans = dfs(grid , i , j , m , n);
                    res = max( res , ans);
                }
            }
        }
        
        return res;
    }
};