// similar to : https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int l = 0;
        int h = 1000000000;
        
        while(l<h){
            int m = (l + h)/2;     
            if(check(grid, m)){
                h = m;
            }else{
                l = m + 1;
            }   
        } 
        return l;
    }
    
    // we keep track that we consider only those paths where maximum abs diff is less than m.
    // if by end we are geeting any path , we return true
    // else we return false.
    
    bool check(vector<vector<int>>& grid , int m){
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>>vis(r, vector<int>(c , 0));
        vector<int>dx = {1, 0 , -1 , 0};
        vector<int>dy = {0 , 1, 0 , -1};
        queue<pair<int, int>>q;
        q.push({0, 0});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                int curx = cur.first;
                int cury = cur.second;
                q.pop();
                
                if(curx==(r-1) and cury==(c-1)){
                    return true;
                }
       
                for(int i =0;i<4;i++){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];
                    
                    if(valid(newx, newy ,r , c) and !vis[newx][newy] and abs(grid[newx][newy]-grid[curx][cury])<=m){
                        q.push({newx, newy});
                        vis[newx][newy] = 1;
                    }
                }
            }   
        }
        return false;
    }
    
    
    bool valid(int x , int y, int r, int c){
        return (x>=0 and x<r and y>=0 and y<c);
    } 
    
};








