
// just check for cycle and connectedness in the graph. Both of these can be done via DFS.

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (auto e : edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        if (hasCycle(neighbors, 0, -1, visited))
            return false;
        for (bool v : visited)
            if (!v) return false; 
        return true;
    }
    bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited) {
        if (visited[kid]) return true;
        visited[kid] = true;
        for (auto neigh : neighbors[kid])
            if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
                return true;
        return false;
    }
};