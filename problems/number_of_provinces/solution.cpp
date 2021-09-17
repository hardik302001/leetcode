// Connected Components in a bidirectional Graph
// As given in the question, we have n nodes. So we will make a visited array for n nodes. then we will start with one node, and mark all its connected nodes as visited=true. So we will count only how many times we have to start this process. that will be our answer.


class Solution {
public:

    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size(),ans=0;
        if(n==0) return 0;

        vector<bool>vis(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(M,vis,i);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& M, vector<bool>& vis, int i)
    {
        vis[i]=true;
        for(int j=0;j<M.size();j++)
            if(M[i][j]==1 && !vis[j])
                dfs(M,vis,j);
    }
};