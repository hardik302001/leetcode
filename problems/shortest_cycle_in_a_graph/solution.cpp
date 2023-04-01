// brute force

// Use the visited array to record the depth.
// Do DFS for all nodes because there might be a case where the depth changes according to which node you visit first.

// Complexity
// Time complexity: O(n^2)
// Space complexity:O(n)

class Solution {
public:
    void dfs(int parent, int src, vector<vector<int>>& adj, int& ans, int d, vector<int>& visited){
        visited[src]=d;
        for(auto nbr:adj[src]){
            if(nbr==parent) continue;
            if(visited[nbr]!=INT_MAX){
                ans=min(ans, abs(visited[nbr]-visited[src])+1);
                continue;
            }
            dfs(src, nbr, adj, ans, d+1, visited);
        }
        return;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        
        int ans=INT_MAX;
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            //show in which order the edges are visited (records the depth)
            vector<int> visited(n,INT_MAX);
            if(visited[i]==INT_MAX){
                dfs(-1,i, adj, ans, 0, visited);
            }          
            
        }
        
        return ans==INT_MAX?-1:ans;
    }
};