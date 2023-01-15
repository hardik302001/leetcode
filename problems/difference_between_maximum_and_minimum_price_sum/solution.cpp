// dp 
// memoise sum of children
// idea  https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/discuss/3052744/Very-Simple-Python-DFS

class Solution {
    vector<unordered_map<int , long long >>dp = vector<unordered_map<int , long long >>(100000);
public:    
    // maximum path sum with src at root
    long long dfs(int src, int par, vector<vector<int>>&g, vector<int>&price){
        
        if(dp[src].count(par)) return dp[src][par];
        long long maxi = 0;
        for(auto nei: g[src]){
            if(nei!=par){
                long long s = dfs(nei , src , g, price);
                maxi = max(maxi , s);
            }
        }
        
        return dp[src][par] = (maxi + price[src]);
        
    }
    
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>>g(n+1);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        long long ans = 0;
        for(int i = 0;i<n;i++){
            long long ma = dfs(i , -1, g, price);
            long long mi = price[i];
            ans = max(ans , ma-mi);
        }
        return ans;
        
    }
};