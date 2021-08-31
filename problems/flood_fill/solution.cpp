class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int newColor) 
    {
        int M = mat.size();
        int N = mat[0].size();
        int old = mat[sr][sc];
        if (old==newColor){    //else it will lead to tle..or keep a vis array!
            return mat;
        }
        
        
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int> dy = {0,1,0,-1};
        
        todo.push({sr,sc});
        
        
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            mat[curx][cury] = newColor;
            todo.pop();
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N , mat) and mat[newx][newy]==old){
                    todo.push({newx, newy});
                    
                }
                
            }   
            
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