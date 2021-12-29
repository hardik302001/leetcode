class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        
        queue<int>q;
        q.push(0);
        
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int topa = q.front();
                q.pop();
                vis[topa] = true;
                for(int i = 0;i<rooms[topa].size();i++){
                    int nxt = rooms[topa][i];
                    if(!vis[nxt]){
                        q.push(nxt);
                    }
                }
                
            }
            
        }
        
        bool ans = true;
        for(auto it: vis){
            if(!it){
                ans = false;
                break;
            }
        }
        
        
        return ans;
    }
};