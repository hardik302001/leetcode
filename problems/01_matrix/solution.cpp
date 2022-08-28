//quite similar as 

//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
//MAP OF HEIGHTEST PEAK

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        vector<vector<int>> dis(M,vector<int>(N,-1));
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                if(mat[i][j]==0)
                { 
                    todo.push({i,j});
                    dis[i][j]=0;
                }
            }
        
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            
            todo.pop();
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N) and dis[newx][newy]==-1){
                    dis[newx][newy] = dis[curx][cury] + 1;
                    todo.push({newx, newy});                    
                }
                
            }   
            
        }
   
        return dis;
            
    }


     bool inside(int x, int y, int &M, int &N) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }

};

   
   