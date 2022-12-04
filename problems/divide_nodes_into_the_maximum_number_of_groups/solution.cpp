/*

 Concept:
=.=.=.=.=.=
* If any two nodes at the same level are connected during bfs proces, return -1
* To know the above, use unordered_map to hash edges.
* Use a initial node and run bfs, we can get a connected component with level that would indicate # of group. However, we don't know which node to start with would yield the maximum # of group. Here, implemented by checkConnectedBfs
* So, iterate each node in that component as the initial node to run bfs. Here, implemented by normalBfs
* Time complexity: O(|V| * |E|) = 500 (nodes) * 10^4 (edges) could be acceptable.

*/

class Solution {
public:
    
    int normalBfs(int start, unordered_map<int, unordered_set<int>>& hashEdges, vector<bool> visited) {
        // here we wont have any odd cycles
        queue<int> q;
        q.push(start);
        visited[start] = true;

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : hashEdges[node]) {
                    if (visited[neighbor]) continue;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            level++;
        }
        return level;
    }
    
    
    int checkConnectedBfs(int start, unordered_map<int, unordered_set<int>>& hashEdges, vector<bool>& visited) {
        vector<int> members;  // all members in this cc
        vector<bool> visitedCopy = visited;
        queue<int> q;
        q.push(start);
        members.push_back(start);
        visited[start] = true;

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> collections;      // elements at current level
            for (int i = 0; i < n; ++i) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : hashEdges[node]) {
                    if (visited[neighbor]) continue;
                    collections.push_back(neighbor);
                    visited[neighbor] = true;
                    q.push(neighbor);
                    members.push_back(neighbor);
                }
            }
            
            // odd length cycle will give -1
            // check if all nodes at the same level have any connection;
            int m = collections.size();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (hashEdges[collections[i]].count(collections[j])) return -1;
                }
            }
            
            level++;
        }
        
        
        // trying all possibilities of group 1 start node , to find the longest chain, 
        int maxGroups = 0;
        for (auto& member : members) {
            maxGroups = max(maxGroups, normalBfs(member, hashEdges, visitedCopy));
        }
  
        return maxGroups;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> hashEdges;

        for (auto& edge : edges) {
            hashEdges[edge[0] - 1].insert(edge[1] - 1);
            hashEdges[edge[1] - 1].insert(edge[0] - 1);
        }
        vector<bool> visited(n, false);
        int maxRes = 0;
        
        for (int node = 0; node < n; ++node) {
            if (visited[node]) continue;
            int result = checkConnectedBfs(node, hashEdges, visited);
            if (result == -1) return -1;
            
            maxRes += result;
        }
        return maxRes;
    }
};