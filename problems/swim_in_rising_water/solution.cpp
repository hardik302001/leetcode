// BINARY SEARCH ON ANSWER  + BFS
// EASY PEASY

// similar to : https://leetcode.com/problems/path-with-minimum-effort/submissions/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0;
        int r = n*n+1;
        
        while(l<r){
            int m = (l + r)/2;
           
            if(check(grid, m)){
                r = m;
            }else{
                l = m + 1;
            }   
        } 
        return l;
    }
    
    // checking if there is any apth such that all values on that path are less than m
    // if any value is greater than m , we ignore it, else we push it into stack
    bool check(vector<vector<int>>& grid , int m){
        int n = grid.size();
        
        if(grid[0][0]>m or grid[n-1][n-1]>m){
            return false;
        }
        vector<vector<int>>vis(n, vector<int>(n , 0));
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
                
                if(curx==(n-1) and cury==(n-1)){
                    return true;
                }
       
                for(int i =0;i<4;i++){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];
                    
                    if(valid(newx, newy , n) and !vis[newx][newy] and grid[newx][newy]<=m){
                        q.push({newx, newy});
                        vis[newx][newy] = 1;
                    }
                }
            }
            
        }
        
        
        return false;
    }
    
    
    bool valid(int x , int y, int n){
        return (x>=0 and x<n and y>=0 and y<n);
    }
};