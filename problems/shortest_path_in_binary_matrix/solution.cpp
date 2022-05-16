class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0,1,1,-1,-1};
        vector<int>dy = {0,1,0,-1,1,-1,1,-1};
        
        vector<vector<int>> dis(M,vector<int>(N,-1));
        todo.push({0,0});
        dis[0][0] = 0;
        if(mat[0][0]==1 or mat[M-1][N-1]==1){
            return -1;
        }
        
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            
            todo.pop();
            
            if(curx==(M-1) and cury==(N-1)){
                return dis[curx][cury]+1;
            }
            
            for(int i = 0;i<8;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N) and dis[newx][newy]==-1 and mat[newx][newy]==0){
                    dis[newx][newy] = dis[curx][cury] + 1;
                    todo.push({newx, newy});                    
                }
                
            }   
            
        }
        
        
        return -1;
            
    }


     bool inside(int x, int y, int &M, int &N) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
        
        
        

};