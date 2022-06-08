class Solution {
public:
    
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int src, int end) {
        if(src == end) {
            path.push_back(src);
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto node : graph[src]){
            path.push_back(src);
            dfs(graph, result, path, node, end);
            path.pop_back();
        }
        
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths; 
        vector<int> path;
        int nodes = graph.size();
        if(nodes == 0) return paths;
        
        dfs(graph, paths, path, 0, nodes - 1);
        return paths;
    }
};