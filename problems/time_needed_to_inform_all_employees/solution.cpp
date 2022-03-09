class Solution {
public:
    int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& inf) {
        vector<int>adj[n+1];
        for(int i = 0;i<n;i++){
            if(manager[i]==-1)continue;
            adj[manager[i]].push_back(i);
        }
        
        int ans = inf[head];
        queue<pair<int, int>>q;
        q.push({head, inf[head]});
        while(!q.empty()){
            auto [node, time] = q.front();
            q.pop();
            for(auto it: adj[node]){
                q.push({it , time + inf[it]});
                ans = max(ans , time + inf[it]);
            }
            
        }
        
        return ans;
        
    }
};