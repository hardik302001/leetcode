// topological sort
// kahn algo
// bfs, remove indegree == 0, nodes, bcz directed graph
// store topo sort ans, it topo sort exists then res array length will be equal to number pf initial nodes

// https://leetcode.com/problems/minimum-height-trees/submissions/




class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        if(n==1)
            return true;
        vector<int>res;
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);//creating adjacent list
            degrees[edges[i][0]]++;
        }
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==0)//adding all the leave nodes
                queue.push(i);
        }
        while(!queue.empty())
        {
            int cur=queue.front();
            queue.pop();
            res.push_back(cur);  
            for(auto &neighbor:adj[cur])                {
                degrees[neighbor]--;//removing current leave nodes
                if(degrees[neighbor]==0)//adding current leave nodes
                    queue.push(neighbor);
            }
        }
        

        return res.size()==n;
    }
};