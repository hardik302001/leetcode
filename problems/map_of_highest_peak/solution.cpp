//similar to 01 MATRIX, 
//ROTTEN ORANGES

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                if(mat[i][j]==1)
                {   mat[i][j] = 0;
                    todo.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        int h = 1;
        while (!todo.empty()) {
            
            int sz = todo.size();
            while(sz--){
                int curx = todo.front().first;
                int cury = todo.front().second;

                todo.pop();

                for(int i = 0;i<4;i++){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];

                    if(inside(newx , newy , M , N , mat) and mat[newx][newy]==-1){
                        mat[newx][newy] = h;
                        todo.push({newx, newy});

                    }

                }   
            }
            h++;
            
        }
        
        
        return mat;
            
    }
    
    
    
    
    bool inside(int x, int y, int &M, int &N, vector<vector<int> > &mat) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
    
};