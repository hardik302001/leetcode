//  https://leetcode.com/problems/minimum-height-trees/discuss/827284/c%2B%2B99-TC-with-explanation-using-bfs-top-sort-%3A)

// similar to https://codeforces.com/contest/1593/submission/131820810
// https://leetcode.com/problems/course-schedule-ii/submissions/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int>res;
        vector<int>degrees(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;//updating how many edges each node has
            degrees[edges[i][0]]++;
        }
        queue<int>queue;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1)//adding all the leave nodes
                queue.push(i);
        }
        while(!queue.empty())
        {
            
            // very important to clear res  , bcz we need last step nodes only!
            res.clear();// clear vector before we start traversing level by level.
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                int cur=queue.front();
                queue.pop();
                res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--;//removing current leave nodes
                    if(degrees[neighbor]==1)//adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    }
};
