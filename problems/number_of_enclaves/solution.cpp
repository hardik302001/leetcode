class Solution {
public:
    int numEnclaves(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        vector<vector<int>> vis(M,vector<int>(N,-1));
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {   
                if(i==0 or j==0 or i==M-1 or j==N-1)
                {
                    if(mat[i][j]==1)
                    { 
                        todo.push({i,j});
                        bfs(M,N, todo, dx, dy, mat);
                    }
                }
            }
        

        long long int c = 0;
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if (mat[i][j] ==1){
                    c++;
                }
            }
        }
        
        return c;
        //return mat;
            
    }
    
    
    void bfs(int M, int N, queue<pair<int, int>> &todo, vector<int>dx, vector<int>dy, vector<vector<int>>& mat){
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            mat[curx][cury] = 0;
            todo.pop();
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N ) and mat[newx][newy]==1){
                    todo.push({newx, newy});
                    
                }
                
            }   
            
        }
    }


     bool inside(int x, int y, int &M, int &N) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
    
    
};