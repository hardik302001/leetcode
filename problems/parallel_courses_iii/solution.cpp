/*
In this question we have to find the path having max-weight , do same as topological sort via using BFS , in topological sorting we will push new element in queue when the indegree will be zero here we push in that thing only but for weight we will compare with already stored value with its original time + parent's time -

maxTime[node] = max(maxTime[node],maxTime[parentNode]+time[node-1]); // node-1 bcz 0 based indexing used in given time array


*/


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<long long int> adj[n+1];
        vector<long long int> indegree(n+1,0);
        vector<long long int> maxTime(n+1,0);
        for(long long int i=0;i<rel.size();i++)
        {
            adj[rel[i][0]].push_back(rel[i][1]);
            indegree[rel[i][1]]++;
        }
        queue<long long int>q;
        for(int i=1;i<=n;i++)
        {
            maxTime[i] = time[i-1];
            if(!indegree[i])
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int ss = q.size();
            for(int i=0;i<ss;i++)
            {
                int parentNode = q.front();q.pop();
                // cout<<node<<" "<<adj[node].size();
                for(long long int child : adj[parentNode])
                {
                    indegree[child]--;
                     maxTime[child] = max(maxTime[child],maxTime[parentNode]+time[child-1]);       //,ost impo line!
                    if(indegree[child]==0)
                    {
                        q.push(child);
                    }
                }
            }
            
            
        }
        long long int ans = -1;
        for(long long int value : maxTime)
            ans = max(ans , value);
        return ans;
    }
};