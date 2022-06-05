// https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1315621/c-easy-peasy-dfs-just-1-observation-matters



class Solution {
public:
    vector<vector<bool>> pac,atl;
    int n,m;
    void dfsp(int i,int j,vector<vector<int>>& h,int prev)
    {
        if(i<0||j<0||i==n||j==m||pac[i][j]||h[i][j]<prev){return;}
        pac[i][j]=true;
        
        int v=h[i][j];
        dfsp(i,j+1,h,v);
        dfsp(i,j-1,h,v);
        dfsp(i+1,j,h,v);
        dfsp(i-1,j,h,v);
    
    }
    
    void dfsa(int i,int j,vector<vector<int>>& h,int prev)
    {
        if(i<0||j<0||i==n||j==m||atl[i][j]||h[i][j]<prev){return;}
        atl[i][j]=true;
        
        int v=h[i][j];
        dfsa(i,j+1,h,v);
        dfsa(i,j-1,h,v);
        dfsa(i+1,j,h,v);
        dfsa(i-1,j,h,v);
    
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        pac.assign(heights.size(),vector<bool>(heights[0].size(),false));
        atl.assign(heights.size(),vector<bool>(heights[0].size(),false));
        n=heights.size();m=heights[0].size();
        for(int i=0;i<n;i++){
            dfsp(i,0,heights,-1);
        }
        
        for(int j=0;j<m;j++){
            dfsp(0,j,heights,-1);
        }
        
        for(int i=0;i<n;i++){
            dfsa(i,m-1,heights,-1);
        }
        
        for(int j=0;j<m;j++){
            dfsa(n-1,j,heights,-1);
        }
        
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j]&&pac[i][j]){
                    ans.push_back(vector<int>{i,j});
                }
            }
        }
        return ans;
    }
};