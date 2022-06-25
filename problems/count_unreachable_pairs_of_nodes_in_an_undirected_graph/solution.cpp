class Solution {
public:
    
    vector<int>vis = vector<int>(100001, 0);
    vector<int>adj[100001];
    int c;
    void dfs(int src){
        vis[src] = 1;
        c++;
        for(auto nei: adj[src]){
            if(!vis[nei]){
                dfs(nei);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long int ans = 0;
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>count;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                c = 0;
                dfs(i);
                count.push_back(c);
            }
        }
        

        
        long long int s= accumulate(count.begin(), count.end() , 0);
        for(auto c: count){
            ans+= c*(s-c);
        }
        
        
        
        return ans/2;
        
        
    }
};