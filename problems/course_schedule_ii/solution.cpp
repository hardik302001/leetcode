// TC : O (V + E) , same as BFS

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
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
        

        if(res.size()==n){
            return res;
        }
        else{
            return {};
        }
    }
};