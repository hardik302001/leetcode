class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        int ans = INT_MIN;
        for(auto x:vals){        // if k==0 -> initial answer
            ans = max(ans , x);
        }
        vector<priority_queue<int>>pq(n+1);
        for(auto x: edges){
            int a = x[0];
            int b = x[1];
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
                ans = max(ans , s);   // bcz what if we start adding negative values, so maximise at every step
            }
        }

        return ans;
        
    }
};