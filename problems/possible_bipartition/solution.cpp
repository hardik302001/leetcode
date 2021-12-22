class Solution {
public:
    
    vector<int>vis,col;
    bool dfs(int v, int c, vector<vector<int>>& graph){
        vis[v]=1;
        col[v]=c;
        for(int child:graph[v]){
            if(vis[child]==0){
                // here c^1 is for flipping 1 by 0 or 0 by 1, that is flip the current color
                if(dfs(child,c^1,graph)==false) 
                    return false;
            }
            else{
                if(col[v]==col[child])
                    return false;
            }
        }
        return true;
    }
    
    
    
    
	bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<vector<int>> graph(n+1);
		//graph adj generation using given vector<vector<int>>dislikes
		for (auto i : dislikes)
		{
			graph[i[0]].push_back(i[1]);
			graph[i[1]].push_back(i[0]);
		}
		//graph coloring using 2 color
		//color are 0 & 1
        
        vis.resize(n+1);
        col.resize(n+1);

        for(int i=1;i<=n;++i){
            if(vis[i]==0 && dfs(i,0,graph)==false){ 
                return false;
            }
        }
        
        return true;
	}

    
};