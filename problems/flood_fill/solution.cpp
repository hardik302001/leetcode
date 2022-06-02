class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<int>dx = {1, 0 , -1 , 0};
        vector<int>dy = {0 , 1 , 0 , -1};
        int m = image.size();
        int n = image[0].size();
        
        queue<pair<int, int>>q;
        q.push({sr , sc});
        int org = image[sr][sc];
        if(org==newColor) return image;
        
        
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                int x = p.first ;
                int y = p.second;
                image[x][y] = newColor;
                
                for(int i = 0;i<4;i++){
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx>=0 and newx<m and newy>=0 and newy<n and image[newx][newy]==org){
                        q.push({newx, newy});
                    }
                }
            }
        }
        
        return image;
    }
};