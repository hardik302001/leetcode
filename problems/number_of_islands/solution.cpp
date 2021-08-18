class Solution {
public:
    
  
    
    int numIslands(vector<vector<char>>& mat) {
        int ans = 0;
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        vector<vector<int>> vis(M,vector<int>(N,-1));
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {   
                    if(mat[i][j]=='1')
                    { 
                        todo.push({i,j});
                        mat[i][j] ='0';
                        ans++;
                        bfs(M,N, todo, mat, dx, dy);
                        
                    }
            }
        
        
        
        return ans;
    }
    
    
    void bfs(int M , int N , queue<pair<int, int>> &todo, vector<vector<char> > &mat, vector<int>dx, vector<int> dy){
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            todo.pop();
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N , mat) and mat[newx][newy]=='1'){
                    todo.push({newx, newy});
                    mat[newx][newy] = '0';
                    
                }
                
            }   
            
        }
        
    
    }





     bool inside(int x, int y, int &M, int &N, vector<vector<char> > &mat) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
    

    
};