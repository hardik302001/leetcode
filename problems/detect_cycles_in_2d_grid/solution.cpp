/*

The main idea is:

Visit every single cell in the grid, but keep in mind that do not visit the same cell twice.

We keep tracking of the last cell we've visited, do not visit the last cell visited, because 2 adjcent cells aren't considered as a cycle.

Keep iterating until our current cell is already visited, then there is a cycle. Why? Because if we've followed idea 2, there must be a previous visit before the last iteration/visit, which means we're back to the origin of the cycle again, in this case, we return true means we found a cycle.
Here is my code in c++:
*/


class Solution {
public:
    bool iscyclic(vector<vector<char>>& grid, vector<vector<bool>> &vis, int curi, int curj, int lasti, int lastj, int tar){
        if(curi < 0 || curj < 0 || curi > grid.size()-1 || curj > grid[0].size()-1 || grid[curi][curj] != tar) return false;    //is valid and shud be same char with which we started
        
        if(vis[curi][curj]) return true;     //if cur is not prev and cur is already visted it means its a cycle
        
        vis[curi][curj] = true;  //mark cur as visted
        
        if((curi+1!=lasti||curj!=lastj) && iscyclic(grid,vis,curi+1,curj,curi,curj,tar)) return true;
        if((curi-1!=lasti||curj!=lastj) && iscyclic(grid,vis,curi-1,curj,curi,curj,tar)) return true;
        if((curi!=lasti||curj+1!=lastj) && iscyclic(grid,vis,curi,curj+1,curi,curj,tar)) return true;
        if((curi!=lasti||curj-1!=lastj) && iscyclic(grid,vis,curi,curj-1,curi,curj,tar)) return true;
        return false;
    }
    
    
    
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(!vis[i][j] && iscyclic(grid,vis,i,j,-1,-1,grid[i][j])) return true;
            }
        }
        return false;
    }
};