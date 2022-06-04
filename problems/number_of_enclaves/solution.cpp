class Solution {
public:
    void dfs(int i , int j , int m , int n , vector<vector<int>>& grid){
        if(i<0 or i>=m or j<0 or j>=n  or grid[i][j]==0){
            return ;
        }
    
        grid[i][j] = 0;
    
        dfs(i+1, j, m , n ,  grid);
        dfs(i-1, j, m , n , grid);
        dfs(i, j+1, m , n ,  grid);
        dfs(i, j-1, m , n , grid);  
            
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if((i==0 or j==0 or i == (m-1) or j==(n-1)) and grid[i][j]==1){
                    dfs(i , j, m , n , grid);
                }
            }
        }    
        
        long long int c = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if (grid[i][j] ==1){
                    c++;
                }
            }
        }
        
        
    
        return c;
        
    }
};