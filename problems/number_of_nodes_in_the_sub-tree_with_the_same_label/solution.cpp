class Solution {
public:
    void dfs(int src , vector<int>&vis , vector<int>&count , vector<vector<int>>&g , vector<int>&res, string &labels ){
        vis[src] = 1;
        for(auto nei: g[src]){
            if(!vis[nei]){
                vector<int> counting(26,0);
                dfs(nei, vis ,counting,g , res ,labels);
                for(int i=0;i<26;i++){
                    count[i]=count[i]+counting[i];
                }
            }
        }
        count[labels[src]-'a']++;
        res[src]=count[labels[src]-'a'];
            
        
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>g(n+1);
        for(auto v:edges){
            int x = v[0];
            int y = v[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        vector<int>res(n);
        vector<int>count(26, 0);
        vector<int>vis(n, 0);
        dfs(0 , vis , count , g, res, labels);
        return res;
    }
};