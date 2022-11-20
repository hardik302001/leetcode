// size of each subtree ceil seats

class Solution {
public:
    long long ans = 0;
	
	// Return total no.of children of the current node including itself
    long long DFS(int src, int seats, vector<bool> &visited, vector<vector<int>> &graph){
        visited[src] = true;
        long long count = 1;
        for(auto adj: graph[src]){
            if(visited[adj]){
                continue;
            }
            count += DFS(adj, seats, visited, graph);
        }
        
        ans += (count + seats - 1)/seats;
        return count;
    }
    
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // Creating graph
        int n = roads.size();
        vector<vector<int>> graph(n+1);
        for(auto it: roads){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        
        vector<bool> visited(n+1, false);
        visited[0] = true;
        
        // Call DFS for each children of capital node
        for(auto it: graph[0]){
            DFS(it, seats, visited, graph);
        }
        
        return ans;
    }
};