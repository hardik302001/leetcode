//we are doing the other way .. we start from nodes not having all 4 directions surrounded, marking them visited..
//then mark all unvisted nodes as X
/*

BETTER USE MULTI SOURCE BFS, startbfs everytime you et new node, rather than collecting all at once, and doing bfs only once...why??

Bcz, suppose border column have all O, you push all of them in queue..
you start bfs, take first node of them, mark all its negihbours as visited(including the whole column)..now you choose the next node for bfs, but it is already marked as visited
, but still it exists in queue...The work that this node had to do , was done by its adjacent(or neighbouring nodes)..so its waste to again and again start bfs...

MAYBE YOU CAN GET TLE!
https://leetcode.com/problems/number-of-enclaves/ for more info

*/



class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        queue<pair<int, int>> todo;
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        vector<vector<int>> vis(M,vector<int>(N,-1));
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {   
                if(i==0 or j==0 or i==M-1 or j==N-1)
                {
                    if(mat[i][j]=='O')
                    { 
                        todo.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            
            todo.pop();
            
            for(int i = 0;i<4;i++){
                int newx = curx + dx[i];
                int newy = cury + dy[i];
                
                if(inside(newx , newy , M , N , mat) and vis[newx][newy]==-1 and mat[newx][newy]=='O'){
                    todo.push({newx, newy});
                    vis[newx][newy] = 1;
                    
                }
                
            }   
            
        }
        
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                if (mat[i][j] =='O' and vis[i][j]==-1){
                    mat[i][j] = 'X';
                }
            }
        }
        
        
        //return mat;       
    }

     bool inside(int x, int y, int &M, int &N, vector<vector<char> > &mat) {
        if ((x < 0 || x >= M || y < 0 || y >= N )) {
            return false;
        }
        return true;
    }
    
    
};