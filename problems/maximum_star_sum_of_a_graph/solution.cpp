class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        int n = vals.size();
        vector<int>indeg(n+1 , 0);
        vector<vector<int>>g(n+1); 
        int ans = INT_MIN;
        for(auto x:vals){
            ans = max(ans , x);
        }
        vector<priority_queue<int>>pq(n+1);
        for(auto x: edges){
            int a = x[0];
            int b = x[1];
            g[a].push_back(b);
            g[b].push_back(a);
            indeg[a]++;
            indeg[b]++;
            pq[a].push(vals[b]);
            pq[b].push(vals[a]);
    
        }
        
        
        for(int i = 0;i<n;i++){
            int s = vals[i];
            int kk = k;
            priority_queue<int>pqq = pq[i];
            while(kk-- and !pqq.empty()){
                auto topa = pqq.top(); pqq.pop();
                s+= topa;
                ans = max(ans , s);
            }
        }
        
        
        
        return ans;
        
    }
};