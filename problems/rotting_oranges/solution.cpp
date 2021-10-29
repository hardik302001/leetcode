/*
    VISIT PREV BRUTE FROCE SOLUTION:FOR EVERY LEVEL WE TARVERSE THE WHOLE MATRIX AGAIN!    O(m*n*n*n) = O(m2n2)
    WE optimise it by BFS, level by level..
    simple code : ans++ when puhed else ignore
    TC = 0(m*n)
    
    
*/





class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        
        int M = mat.size();
        int N = mat[0].size();
        int ans = 0;
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++)
            {
                if(mat[i][j]==2)
                { 
                    todo.push({i,j});
                }
            }
        }
        
        while (!todo.empty()) {
            int sz = todo.size();
            bool pushed = false;  //this is very impo
            while(sz--){         //for level order we need it (bcz we r doing per second traversal)
                int curx = todo.front().first;
                int cury = todo.front().second;

                todo.pop();

                for(int i = 0;i<4;i++){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];

                    if(inside(newx , newy , M , N , mat) and mat[newx][newy]==1){
                        mat[newx][newy] = 2;
                        todo.push({newx, newy});
                        pushed = true;
                    }

                }   
            }
            if(pushed){
                ans++;
            }
        }
        
        
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 1)
                    return -1;
            }
        }


        return ans;
        
    }
    
    
     bool inside(int x, int y, int &M, int &N, vector<vector<int> > &mat) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
    
    
};