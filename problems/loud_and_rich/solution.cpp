class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n = quiet.size();
        vector<int> indg(n,0), ans(n,INT_MAX);
        vector<vector<int>> g(n);
        queue<int> q;
        
        //build graph and calculate indegrees
        for(int i=0;i<richer.size();i++){
            g[richer[i][0]].push_back(richer[i][1]);
            indg[richer[i][1]]++;
        }
       
        //initialise ans array and push nodes with 0 degrees into queue
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(indg[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i : g[curr]){
                //if parent node having more money is quieter , update
                if(ans[i] == INT_MAX || quiet[ans[i]] > quiet[ans[curr]])   // very impostant, not quiet[i], its quiet[ans[i]]
                    ans[i] = ans[curr];
                
                if(--indg[i]==0)
                    q.push(i);
            }
        }
        return ans;
    }
};