// also see: https://leetcode.com/problems/cheapest-flights-within-k-stops/


// o(n+elogn)
// pure djisktra


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
                    pq.push({dis[edge.first] , edge.first});  // push edge
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


// Dijkstra's Algorithm takes O(ElogN). Finding the minimum time required in signalReceivedAt takes O(N).
// tc : O(n+elogn)  





// O(ne)
// bellman ford :  fucking constraints, giving TLE
// hardly passed 

/*
#define INF 1000000000000
#define ll long long
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<ll> dist(n+1, INF);   // bcz 1 based indexing
        dist[k] = 0; 
        for(int i = 1;i<=n-1;i++) {                     // do relaxing (n-1) times
            for(auto it: times) {
                if(dist[it[0]]!=INF and dist[it[0]] + it[2] < dist[it[1]]) {
                    dist[it[1]] = dist[it[0]] + it[2]; 
                }
            }
        }
        ll ma = 0;
        for(int i = 1;i<=n;i++){
            ma=max(ma , dist[i]);
        }
    
        return ma==INF?-1:ma;
    }
};

*/