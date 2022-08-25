/*


    VISIT PREV BRUTE FROCE SOLUTION:FOR EVERY LEVEL WE TARVERSE THE WHOLE MATRIX AGAIN!    O(m*n*n*n) = O(m2n2)
    WE optimise it by BFS, level by level..
    simple code : ans++ when pushed else ignore
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
            }else{
                break;
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

// --------------------------------------------------------------------------------

/*
    
    THIS IS BRUTE FROCE SOLUTION:FOR EVERY LEVEL WE TARVERSE THE WHOLE MATRIX AGAIN!
    O(m*n*n*n) = O(m2n2)
    
    Second trick in this question is how to keep track of new 2 that we get on each level!
    I took a vis matrix with all -1
    I traverse matrix,  I find 2 such that its vis is -1, I  look in all 4 direction having 
    1, so I make them 2, and mark those new 2 as vis = 0..so that I can differentiate between the new 2(formed from 1) and the old 2 that we present previously(having vis = -1)
    
    
    Now when traversal is complete, I will mark all new 2(vis = 0) back to vis = -1, so that again I need not change my logic!
    
    Rest all logic is same!
    
    GFG did this same thing using a variable no = 2, and changing the logic, A bit weird!

*/


/*


class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        
        int M = mat.size();
        int N = mat[0].size();
        bool changed = false;
        int ans = 0;
        vector<vector<int>> vis( M , vector<int> (N, -1));
        
        while (true) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (mat[i][j] == 2 and vis[i][j]==-1) {  // very impo, vis shud be -1
                       
                        if (inside(i + 1, j,M,N,mat) and mat[i + 1][j] == 1) {
                            vis[i+1][j] = 0;
                            mat[i + 1][j] = 2;
                            changed = true;
                        }
                        if (inside(i , j+1,M,N,mat) and mat[i][j + 1] == 1) {
                            mat[i][j + 1] = 2;
                            vis[i][j+1] = 0;
                            changed = true;
                        }
                        if (inside(i - 1, j,M,N,mat) and mat[i - 1][j] == 1) {
                            vis[i-1][j] = 0;
                            mat[i - 1][j] = 2;
                            changed = true;
                        }
                        if (inside(i, j-1 ,M,N,mat) and mat[i][j - 1] == 1) {
                            mat[i][j - 1] = 2;
                            vis[i][j-1] = 0;
                            changed = true;
                        }
                        vis[i][j] = 1;
                    }
                    
                }
            }
            
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if(vis[i][j]==0){
                        vis[i][j] = -1;
                    }
                }
            }

        
            // if no rotten orange found it means all
            // oranges rottened now
            if (!changed)
                break;
            changed = false;
            ans++;
       
        }  
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {

                // if any orange is found to be
                // not rotten then ans is not possible
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

*/