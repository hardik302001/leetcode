class Solution {
public:
    int ans = 0;
    
    int dfs(int x , int y, int m , int n , vector<vector<int>>&vis, vector<vector<int>>&grid){
        if(x<0 or x>=m or y<0 or y>=n or vis[x][y]==1 or grid[x][y]==0) return 0;
        int c = 0;
        c++;
        vis[x][y] = 1;
        grid[x][y] = 0;
        
        c+=dfs(x+1, y , m , n , vis, grid);
        c+=dfs(x, y+1 , m , n , vis , grid);
        c+=dfs(x-1, y , m , n , vis , grid);
        c+=dfs(x, y-1 , m , n , vis , grid);
        return c;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>vis(m , vector<int>(n , 0));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    int x = dfs(i , j, m , n, vis , grid);
                    ans = max( ans , x);
                }
            }
        }
        
        
        return ans;
    }
};


/*

class Solution {
public:
    int ans = 0;
    int c;
    
    void dfs(int x , int y, int m , int n , vector<vector<int>>&vis, vector<vector<int>>&grid){
        if(x<0 or x>=m or y<0 or y>=n or vis[x][y]==1 or grid[x][y]==0) return;
        c++;
        vis[x][y] = 1;
        grid[x][y] = 0;
        
        dfs(x+1, y , m , n , vis, grid);
        dfs(x, y+1 , m , n , vis , grid);
        dfs(x-1, y , m , n , vis , grid);
        dfs(x, y-1 , m , n , vis , grid);
        
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>vis(m , vector<int>(n , 0));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    c = 0;
                    dfs(i , j, m , n, vis , grid);
                    ans = max( ans , c);
                }
            }
        }
        
        
        return ans;
    }
};



*/