// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/discuss/1844100/C%2B%2B-3-Dijkstra's

/*
Idea
for each node i we calculate the following value
w[i] := dist(src1, i) + dist(src2, i) + dist(i, dest)
where dist(a, b) is defined as the length of the shortest path from node a to node b.
then the answer would be the minimum value among all w[i]s.
to obtain the distance functions, we have to perform Dijkstra's Algorithm three times:
starting from src1 to get dist(src1, *)
starting from src2 to get dist(src2, *)
starting from dest in the edge-reversed graph to get dist(*, dest)


Time Complexity:
O(E log E + n), where E denotes the number of edges in the graph.
Space Complexity:
O(E + n)
*/

    

#define ll long long
const ll inf = 1e18;
class Solution {
public:
	long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
		// build the graphs
		vector<vector<pair<ll, ll>>> adj(n);
		vector<vector<pair<ll, ll>>> rev(n);  // the graph with reversed edges
		int u, v, w;
		for (auto& e : edges) {
			u = e[0], v = e[1], w = e[2];
			adj[u].push_back(make_pair(v, w));
			rev[v].push_back(make_pair(u, w));
		}
		// Dijkstra
		vector<ll> dist_from_src1 = djisktra(adj, src1);
		vector<ll> dist_from_src2 = djisktra(adj, src2);
		vector<ll> dist_to_dest   = djisktra(rev, dest);
        
		// find the smallest w[i]
        ll ans = inf;
        for (int i = 0; i < n; ++i) {
            if (dist_from_src1[i] == inf || dist_from_src2[i] == inf || dist_to_dest[i] == inf)continue;
            ans = min(ans, dist_from_src1[i] + dist_from_src2[i] + dist_to_dest[i]);
        }
        return ans == inf ? -1 : ans;
	}

  
    vector<ll> djisktra(vector<vector<pair<ll, ll>>> &graph, int k ) {
        ll n = graph.size();
        vector<ll>dis(n, inf);
        priority_queue<pair<ll , ll> , vector<pair<ll, ll>>, greater<pair<ll ,ll>>>pq;
        pq.push({0,k});
        dis[k] = 0;
        
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (d> dis[node])continue;
            for(auto edge:graph[node]){
                if(d + edge.second<dis[edge.first]){
                    dis[edge.first] = d + edge.second;   
                    pq.push({dis[edge.first] , edge.first});
                }
            }   
        }   
        return dis;
    }    
};


/*

What will happen if I go from some node "i" to dest, like find min weight path from some node "i" to dest ?
I mean there would be some silly logic that I am missing, or I am too dumb.


you need to find shortest distance from i to dest. If you move from i to dest in the same graph then you need to compute shortest distance from all the i's. Which will take O((n+Elogn)*n) time and space and we can't afford that in given constraints.
So, how to improve???
As you can see that we always need to find shortest distance from i to dest. Here dest is not changing So we can find shortest distance from dest to all other nodes, which will take O(n) time and O(n) space, but we can't do that in original graph as in original graph edges are from i to dest so we reverse the edges. And now dd[i] actually means distance from i to dest.
 
Bcz our "i" is changing n times, so we need to calculate dist from "i" to dest n times...
But if we do the reverse that is distance from dest to all "i" in one djisktra traversal, that is more optimised...

*/

