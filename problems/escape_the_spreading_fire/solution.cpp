class Solution {
public:
    vector<int>dx = {1, 0 , -1, 0};
    vector<int>dy = {0, -1, 0 , 1};
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>fire_time(m , vector<int>(n, -1));
        queue<pair<int, int>>q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1) {
                    q.push({i, j});
                   
                }
            }
        }
        
        int time = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();
                q.pop();
                fire_time[x][y] = time;
                for(int i = 0;i<4;i++){
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(valid(newx, newy , m, n) and grid[newx][newy]==0 and fire_time[newx][newy]==-1){
                        q.push({newx, newy});
                    }          
                }
            }
            time++;
        }
        
        
        // fire_time matrix , tells at what time will fire reach at current index
        // fire_time[alpha][beta]==-1, fire will never reach at {alpha, beta}
        
        int l = 0;
        int r = n*m+1;
        int ans = -1;
        while(l<r){
            int mid = l + (r-l)/2;   
            if(check(mid, fire_time, grid)){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        // if fire will not reach at end index, and we an reach at end index(not stopped by walls, means ans != -1,), then we will return 10e9
        // else we return ans(if reachable [ non negative value])
        // else -1 (if not reachble, stuck in fire)
        return (fire_time[m-1][n-1]==-1 and ans!=-1)?1000000000:ans;
    }
    
    
    bool check(int mid, vector<vector<int>>&fire_time , vector<vector<int>>grid){
        // updating grid, thats why passed as copy
        int m = grid.size();
        int n = grid[0].size();
        
        int curtime = mid + 0;
        queue<pair<int, int>>q;
        q.push({0,0});
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front();
                q.pop();
                
                // priority is , if fire reach before, then continue
                if(fire_time[x][y]!=-1 and fire_time[x][y]<curtime) continue;
                
                // if we reach end, then irrespective of fire position we will return true
                if(x == m-1 and y == n-1)   return true;
                
                // else if we are anywhere else, and fire also reach at same time, then we get stuck in fire
                if(fire_time[x][y]!=-1 and fire_time[x][y]==curtime) continue;
                
                
                for(int i = 0;i<4;i++){
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(valid(newx, newy , m, n) and grid[newx][newy]== 0){
                        grid[newx][newy] = 2;   // update grid
                        q.push({newx, newy});
                    }          
                }
            }
            curtime++;
        }
            
        return false;
    }
    
    
    
        
    bool valid(int x, int y , int m , int n ){
        return (0<=x and x<m and 0<=y and y<n);
    }
    
};