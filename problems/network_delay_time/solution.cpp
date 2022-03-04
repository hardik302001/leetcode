#define INF 1000000000000
#define ll long long
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< vector<pair<int , int> >>graph(n+1);
        for(auto x:times){
            graph[x[0]].push_back({x[1], x[2]});
        }
        
        vector<ll>dis(n+1, INF);
        priority_queue<pair<int , int> , vector<pair<int, int>>, greater<pair<int ,int>>>pq;
        pq.push({0,k});
        dis[k] = 0;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto edge:graph[node]){
                if(d + edge.second<dis[edge.first]){
                    dis[edge.first] = d + edge.second;
                    pq.push({dis[edge.first] , edge.first});
                }
            }
            
        }
        
        ll ma = 0;
        for(int i = 1;i<=n;i++){
            ma=max(ma , dis[i]);
        }
    
        return ma==INF?-1:ma;
    
    }
};