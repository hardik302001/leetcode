
// 1 and n are in same cc , bcz if it would have been the otherwise, then there shud be like print -1 , if we cant fin dpath between 1 and n , so they are in same cc
// we dont care abt rest of elements, or more than one cc

//  path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path, so final answer will be minimum cost of all elements in that cc

class Solution {
public:
    
    int ans = 1000000;
    vector<int>vis = vector<int>(200001 , 0);
    void dfs(int x , vector<vector<pair<int, int>>>&g){
        vis[x] = 1;
        for(auto nei: g[x]){
            ans = min(ans ,nei.second);  // we wont do it inside vis , bcz we want to find min of all path , and vis will reject some of the paths , bcz nodes conncted would have been already visited.
            if(!vis[nei.first]){
                dfs(nei.first , g);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>g(n+1);
        for(auto v: roads){
            g[v[0]].push_back({v[1] , v[2]});
            g[v[1]].push_back({v[0] , v[2]});
        }
        dfs(1 , g);
        return ans;
    }
};