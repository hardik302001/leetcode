class Solution {
    vector<vector<int> > vis;
    int m,n;
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    queue<pair<int,int> > que;
    
public:
    void dfs(int i,int j, vector<vector<int>>&mat){
        vis[i][j]=1;
        que.push({i,j});
        for(int dir=0;dir<4;dir++){
            int xd=i+x[dir];
            int yd=j+y[dir];
            if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1){
                if(!vis[xd][yd] && mat[xd][yd]==1){
                    dfs(xd,yd, mat);
                }
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& mat) {
        m=mat.size();
        if(m==0) return 0;
        n=mat[0].size();

        vis.resize(m,vector<int>(n,0));
        int flag=0;  // to keep track of island
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    dfs(i,j, mat);   // putting all lands of any island in queue
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        
        //now start exploring from all lands of that island towrads another island
        int l=0;
        
        while(!que.empty()){
            int len=que.size();
            while(len--){
                pair<int,int> poi=que.front();
                que.pop();
                
                for(int dir=0;dir<4;dir++){
                    int xd = poi.first + x[dir];
                    int yd = poi.second + y[dir];
                    if(xd>=0 && yd>=0 && xd<=m-1 && yd<=n-1 and !vis[xd][yd]){
                        if(mat[xd][yd]==0){
                           que.push({xd,yd});
                           vis[xd][yd] = 1;       // always mark it visited here while pushing, else it will be again pushed to queue by all other 3 neighbours also...and it will give TLE
                       }else{
                            return l;
                        }
                        
                    }
                }
            }
            
            l++;
        }
        return -1;
    }
};      