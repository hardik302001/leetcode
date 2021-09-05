class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        vector<vector<int>> dis(M,vector<int>(N,-1));
 
        vector<vector<int> > res;
        int z = 0;
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
            {
                if(mat[i][j]==1){
                    vector<int>ans;
                    int fx = -1;
                    int fy = -1;
                    todo.push({i,j});
                    mat[i][j] = 0;
                    ans.push_back(i);
                    ans.push_back(j);
                    auto p = bfs(mat, M,N, todo,dx,dy,fx,fy);
                    ans.push_back(p.first);
                    ans.push_back(p.second);
                    
                    res.push_back(ans);
                }
            }

        return res;
            
    }

    
    
    pair<int,int> bfs(vector<vector<int>>& mat,int M, int N, queue<pair<int, int> > &todo, vector<int> dx,vector<int> dy, int fx, int fy){
        
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            fx = curx;
            fy = cury;                
            // cout<<fx<< " "<<fy<<endl;
            todo.pop();
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N , mat) and mat[newx][newy]==1){
                    todo.push({newx, newy});
                    mat[newx][newy] = 0;

                }
                
            }   
            
        }
        
        return make_pair(fx,fy);
    }



     bool inside(int x, int y, int &M, int &N, vector<vector<int> > &mat) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }

        
        
     
};