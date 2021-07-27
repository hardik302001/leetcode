class Solution 
{
public:
    void helper(vector<vector<int>>&image,vector<vector<bool>>&vis,int sr,int sc,int newColor,int prev)
    {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=prev || vis[sr][sc])
        {
            return;
        }
        vis[sr][sc]=true;
        image[sr][sc]=newColor;
        helper(image,vis,sr+1,sc,newColor,prev);
        helper(image,vis,sr,sc+1,newColor,prev);
        helper(image,vis,sr-1,sc,newColor,prev);
        helper(image,vis,sr,sc-1,newColor,prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n=image.size(),m=image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false)); //use vis for backup, to avoid rte and inf looping
        if(newColor==image[sr][sc]){
            return image;
        }
        helper(image,vis,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};