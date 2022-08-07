class Solution {
public:
    int c = 0;
    unordered_set<int>s;
    vector<int>adj[100001];    
    void dfs(int src, vector<int>&vis){
        c+=1;
        vis[src] = 1;
        for(auto nei: adj[src]){
            if(!vis[nei] and !s.count(nei)){
                dfs(nei, vis);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(auto x: restricted){
            s.insert(x);
        }
        vector<int>vis(n+1, 0);
        dfs(0, vis);
        return c;
        
    }
};