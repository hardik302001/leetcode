class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);     
        queue<int>q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int topa = q.front();
                q.pop();

                for(int i = 0;i<rooms[topa].size();i++){
                    int nxt = rooms[topa][i];
                    if(!vis[nxt]){
                        q.push(nxt);
                        vis[nxt] = true;
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


/*
class Solution {
public:

    void dfs(vector<vector<int>> &graph, int s, vector<bool> &vis){
        vis[s] = true;
        for(int i = 0; i < graph[s].size(); i++){
            if(!vis[graph[s][i]]){
                dfs(graph, graph[s][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n=rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        for(i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
*/