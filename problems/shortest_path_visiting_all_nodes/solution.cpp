// sry to say , but muje bitmask nhi aata , and i m submittting it just for sake of daily contest

class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n=graph.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>((1<<n),0));
        
        for(int i=0;i<n;++i){
            q.push({i,(1<<i)});
            if((1<<i) == ((1<<n)-1))return 0;
            vis[i][(1<<i)]=1;
        }
        
        int step=0;
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                int next=q.front().first , mask=q.front().second ;
                q.pop();
                
                for(int x:graph[next]){
                    int newmask=mask|(1<<x);
                    
                    if(vis[x][newmask]==0){
                        if(newmask==((1<<n)-1))return step+1;
                        vis[x][newmask]=1;
                        q.push({x,newmask});
                    }
                    
                }
                
            }
            
            step++;
        }
        
        return 0;
        
    }
};