// house robber 3

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<list<int>> g(n);
        for (auto& edge: edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> cnts(n, 0);
        for (auto& trip: trips) {
            BFS(g, cnts, trip[0], trip[1]);
        }
        vector<int> weights(n);
        for (int i=0; i<n; i++) {
            weights[i] = cnts[i]*price[i];
        }
        auto [half, noHalf] = DFS(g, weights, 0, -1);
        return min(half, noHalf);
    }
    pair<int, int> DFS(vector<list<int>>& g, vector<int>& weights, int root, int prev) {
        int rootHalf = weights[root]/2;
        int rootNoHalf = weights[root];
        for (int adj: g[root]) {
            if (adj == prev) continue;
            auto [half, noHalf] = DFS(g, weights, adj, root);
            rootHalf += noHalf;
            rootNoHalf += min(half, noHalf);
        }
        return {rootHalf, rootNoHalf};
    }
    void BFS(vector<list<int>>& g, vector<int>& cnts, int start, int end) {
        int n = g.size();
        vector<bool> visited(n, false);
        vector<int> prev(n, -1);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == end) break;
            if (visited[node]) continue;
            visited[node] = true;
            for (int adj: g[node]) {
                if (visited[adj]) continue;
                prev[adj] = node;
                q.push(adj);
            }
        }
        int x = end;
        while (x != -1) {
            cnts[x]++;
            x = prev[x];
        }
    }
};