// dfs solution: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/discuss/1822035/C%2B%2B-oror-DFS-oror-With-Comments-oror-Simple

// bfs solution
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            degrees[edges[i][1]]++;//updating how many edges each node has
        }
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==0)//adding all the leave nodes
                queue.push(i);
        }
        while(!queue.empty())
        {
            int size=queue.size();
            for(int i=0;i<size;i++)
            {    
                int cur=queue.front();
                queue.pop();
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--;//removing current leave nodes
                    for(auto&x:ans[cur]){
                        ans[neighbor].insert(x);
                    }
                    ans[neighbor].insert(cur);
                    if(degrees[neighbor]==0)//adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        
        vector<vector<int>> res(n);
        for(int i = 0;i<n;i++){
            vector<int> v(ans[i].begin(), ans[i].end());
            res[i] = v;
        }
        
        return res;
        
    }
};