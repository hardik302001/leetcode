class Solution {
public:
    vector<int>dx = {2, 2, -2, -2, 1, -1, 1, -1};
    vector<int>dy = {1, -1, 1, -1, 2, 2, -2, -2};
    bool dfs(int x, int y , int sz , int cur , vector<vector<int>>& grid){
        if(x<0 or y<0 or x>= sz or y>= sz) return false;
        if(grid[x][y]!=cur) return false;
        else                cur+=1;
        grid[x][y]=-1;
        if(cur==sz*sz) return true;
        bool ans = false;
        for(int i = 0;i<8;i++){
            ans = ans | dfs(x+dx[i] , y+dy[i] , sz , cur , grid );
        }
        return ans;
        
    }
    
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int sz = grid.size();
        bool ans = dfs(0 , 0 , sz , 0 , grid);
        return ans;
    }
};