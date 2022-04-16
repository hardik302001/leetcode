// https://leetcode.com/problems/maximum-score-of-a-node-sequence/discuss/1953669/Python3-Explanation-with-pictures-top-3-neighbors
// Time complexity:
// O(E log(E)) for adjacency list sorting
// O(E*9) = O(E) for iterating over edges
// Total: O(E log(E))
// E is edges count

class Solution {
public:
    bool static compare(pair<int, int>&x , pair<int, int>&y){
        return x.first>y.first;    
    }
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int n = scores.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> adj2(n);
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        
        for(int i = 0;i<n;i++) {
            vector<pair<int , int>>p;
            for(auto el: adj[i]){
                p.push_back({scores[el] , el});
            }
            sort(p.begin(), p.end(), compare);
            for(int x = 0;x<p.size();x++){
                adj2[i].push_back(p[x].second);
            }
        }
        
        
        int result = -1;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int base = scores[u] + scores[v];
            for (int i = 0; i < min(3, (int)adj2[u].size()); ++i) {
                int x = adj2[u][i];
                
                if (x == v) continue; // intersection - not allowed, continue
                
                for (int j = 0; j < min(3, (int)adj2[v].size()); ++j) {
                    int y = adj2[v][j];
                    
                    if (y == u || x == y) continue; // intersection - not allowed, continue
                    
                    result = max(result, base + scores[x] + scores[y]);
                }
            }
        }
        
        return result;
    }
};