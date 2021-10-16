class Solution {
public:
    vector<int >adj[100001];
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        for(auto p:edges){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = 0;
        queue<int>q;
        q.push(0);
        vector<int> dis(n,-1);
        dis[0] = 0;
        while(!q.empty()){
            int cur = q.front();            
            q.pop();
            
            for(auto node: adj[cur]){
                if(dis[node]==-1){
                    dis[node] = dis[cur] + 1;
                    q.push(node);
                }
            }
        }
        int res = 0;
        for(int i = 1; i<n; i++) {
            int tot = 2*dis[i];
            if(tot%patience[i]==0){
                tot = tot - patience[i];   //relative
            }
            else{
                tot = tot - (tot%patience[i]);   // relative steps done by last paxket to reach back to end
            }
            int lastIn = dis[i]*2  + tot;
            res = max(res, lastIn);   //max for each node..bcz everything depend upon patience[i]
        }
        return res+1; 
        
        // since till res time all messages has beed arrived so +1
        //        #Add +1, the current answer is the last time the packet is recieved by the target server (still active).
        //        #We must return the first second the network is idle, therefore + 1
        
    }
};