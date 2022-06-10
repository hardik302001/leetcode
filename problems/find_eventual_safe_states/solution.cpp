// reverse and topo sort
// think on it for some time

// [[],[0,2,3,4],[3],[4],[]]

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n=graph.size();
        unordered_map<int,vector<int>> next;  // adj list for rev graph
        unordered_map<int,int> odegree;  // out degree of actual graph
        unordered_map<int,bool> visited;
        for (int i=0;i<n;++i){
            odegree[i]=graph[i].size();
            visited[i]=false;
            for (auto j:graph[i]) next[j].push_back(i);
        }
        
        vector<int> ans;
        while (true){
            bool flag=false;
            for (int i=0;i<n;++i)
                if (odegree[i]==0&&!visited[i]){
                    flag=true;
                    visited[i]=true;
                    ans.push_back(i);
                    for (auto j:next[i]) --odegree[j];
                }
            if (!flag) break;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};