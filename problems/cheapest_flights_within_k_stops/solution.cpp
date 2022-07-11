// also see this question better approach in future...more better approach than BFS...or other djisktra apprah or some dp shhit..

// we dont need to consider cost here.. our priority is k nodes first..., we dont want nodes with small cost first here...

/*
#define INF 1000000000

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int> >adj[n+1];
        
        for(auto v:flights){
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        vector<int>dis(n+1, INF);
        queue<pair<int, int>>q;
        q.push({0 , src});
        dis[src] = 0;
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [d, node] = q.front();
                q.pop();
             
                for(auto edge:adj[node]){
                    if(d + edge.second<dis[edge.first]){
                        dis[edge.first] = d + edge.second;
                        q.push({dis[edge.first] , edge.first});
                    }
                }
                
            }
            level++;
            if(level==k+1){
                break;
            }
        }

        return dis[dst]==INF?-1:dis[dst];
    }
};
*/


// Running K iterations would give the lowest cost given up to K flights.
// However, the question is asking for the lowest cost given up to K transfers
// so we will do (k+1) relaxing iterations

#define INF 1000000000

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dis(n+1, INF);
        dis[src] = 0;
        
        for(int i = 1;i<=(k+1);i++){   // bcz k+1 relaxing iteration allowed
            vector<int>tmp(dis);  // very important to use seperate array , bcz if we are updating dis while traversing, it will not give correct answer uptil kth iterations, but eventually it will give correct answer for nth iterations, bcz in total we have (n-1) iterations .. for (n-1) edges..
            // see for more info: https://leetcode.com/problems/network-delay-time/
            
            for(auto edge: flights){
                if(dis[edge[0]]!=INF and dis[edge[0]] + edge[2] < tmp[edge[1]]){
                    tmp[edge[1]] = dis[edge[0]] + edge[2];
                }
            }
            
            dis = tmp;
        }
        
        return dis[dst]==INF?-1:dis[dst];
            
    }
};