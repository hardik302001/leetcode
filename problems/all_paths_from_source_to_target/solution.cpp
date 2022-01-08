class Solution {
public:
    
    //I  cant do &path in function arguement bcz, I want my path to have different values in different dfs...
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& path, int src, int end) {
        
        path.push_back(src);
        if(src == end) {
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        for(auto node : graph[src])
            dfs(graph, result, path, node, end);
        path.pop_back();
        
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