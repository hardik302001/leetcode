class Solution {
public:
    void dfs(int i , int j , int m , int n , vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool& f){
        
        // we pass f as refernce bcz , even if we know that sub-island is not possible we need not stop, we need to traverse full sub-island and mark it as visited, else we get WA
        if(i<0 or i>=m or j<0 or j>=n or grid2[i][j]==0){
            return;
        }
        if(grid1[i][j]==0)f = false;
        grid2[i][j] = 0;
        
        dfs(i+1 , j , m , n, grid1, grid2, f);
        dfs(i , j+1 , m , n, grid1, grid2, f);
        dfs(i-1 , j , m , n, grid1, grid2, f);
        dfs(i , j-1 , m , n, grid1, grid2, f);
        
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j =0 ;j<n;j++){
                if(grid2[i][j]==1){
                    bool f = true;
                    dfs(i , j , m , n , grid1, grid2, f); 
                    ans+= int(f);
                }
            }
        }
        
        return ans;
    } 
};