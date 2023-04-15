// bfs or djisktra

/*
1. Calculating the shortest path using bfs.
2. While doing so just need to keep tracking of the cost of the node from the source in vis array.
3. Traverse to the node, only if moving to this will reduce the cost.
*/


class Graph {
public:
    vector<vector<pair<int,int>>> g;
    
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto e: edges){
            g[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
        g[e[0]].push_back({e[1], e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        if(node1 == node2) return 0;
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        vector<int> vis(g.size(), INT_MAX);
        q.push({node1, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(auto node: g[p.first]){
                int newCost = node.second + p.second;
                if(node.first == node2 ) ans = min(ans, newCost );
                if(vis[node.first] >= newCost  ){
                    vis[node.first] = newCost;
                    q.push({node.first, newCost});
                }
                
            }
        }
        return (ans == INT_MAX)?-1:ans;
    }
};