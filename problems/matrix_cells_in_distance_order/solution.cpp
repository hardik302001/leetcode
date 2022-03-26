class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rc, int cc) {
        vector<vector<int>>ans;
        queue<pair<int, int>>q;
        vector<vector<bool>>vis(rows, vector<bool>(cols , false));
        q.push({rc , cc});
        vis[rc][cc] = true;
        vector<int>dx = {1 , 0 , - 1, 0};
        vector<int>dy = {0 , 1 , 0 , -1};
        
        while(!q.empty()){
            auto [x , y] = q.front();
            ans.push_back({x , y});
            // cout<<x<<" "<<y<<endl;
            q.pop();
            
            
            for(int i= 0;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx>=0 and newx<rows and newy>=0 and newy<cols and !vis[newx][newy]){
                    vis[newx][newy] = true;
                    q.push({newx, newy});
                }
            }   
        }
        
        return ans;
    }
};