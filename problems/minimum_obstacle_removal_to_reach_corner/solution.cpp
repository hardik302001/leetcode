class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int ans = 1000000;
        
        // use pairs , i was using vector and it gave TLE
        priority_queue<pair<int , pair<int, int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>q;  // min heap , minimum obstacle count explore first
        
        q.push({0 , {0 , 0}});
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>dx = {0 ,1 , 0 , -1};
        vector<int>dy = {1 , 0 , -1 , 0};
        vector<vector<int>> obs(m,vector<int>(n,-1));
        obs[0][0] = 0;
        
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto cur = q.top();
                q.pop();
                
                int curx = cur.second.first;
                int cury = cur.second.second;
                int o = cur.first;
                
                if(curx==(m-1) and cury==(n-1)){
                    return o;
                }
                
                for(int i = 0;i<4;i++){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];
                    
                    if(newx<0 or newy<0 or newx>=m or newy>= n){
                        continue;
                    }
                    
                    if(obs[newx][newy]!=-1){
                        if(grid[newx][newy]==0){
                            if(obs[newx][newy]<=o){
                                continue;
                            }else{
                                obs[newx][newy] = o;
                                q.push({o ,{newx, newy}});
                            }
                        }else{
                            if(obs[newx][newy]<=o+1){
                                    continue;
                            }else{
                                obs[newx][newy] = o+1;
                                q.push({o+1, {newx, newy}});
                            }
                        }
                    }else{
                        if(grid[newx][newy]==0){
                            obs[newx][newy] = o;
                            q.push({o , {newx, newy}});
                        }else{
                            obs[newx][newy] = o+1;
                            q.push({o+1, {newx, newy}});
                        }  
                    }  

                    
                }
                    
            }
            
        }
    
        
        return ans;
        
        
    }
};