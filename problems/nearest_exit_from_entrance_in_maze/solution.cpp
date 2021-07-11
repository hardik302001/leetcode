//STANDARD BFS ON GRID QUES...MUST REMEMEBER THE CODE..COME BACK HERE AGAIN


class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& start) {
        int M = maze.size();
        int N = maze[0].size();
        int dist[M][N];
        queue<pair<int, int>> todo;
        todo.push({ start[0], start[1]});
        dist[start[0]][start[1]] = 0;          //dist 0
        maze[start[0]][start[1]] = '+';       //vis marked
        vector<int> dx = {-1, 0,1, 0};
        vector<int>dy = {0,1,0,-1};
        
        while (!todo.empty()) {
            int curx = todo.front().first;
            int cury = todo.front().second;
            
            todo.pop();
            
            for(int i = 0;i<4;i++){
                if(inside(curx + dx[i] , cury + dy[i],M,N,maze)){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];
                    cout<<newx<<" "<<newy<<endl;
                    dist[newx][newy] = dist[curx][cury] + 1;
                    maze[newx][newy] = '+';
                    todo.push({newx, newy});
                    
                    if(border(newx,newy,M,N)){
                        return dist[newx][newy];
                    }
                    
                }
                
            }   
            
        }
        
        
        return -1;
    }
    
    bool border(int x, int y, int &M, int &N) {
        return (x == 0 || y == 0 || x == M - 1 || y == N - 1);
    }
    
    bool inside(int x, int y, int &M, int &N, vector<vector<char> > &maze) {
        if (x < 0 || x >= M || y < 0 || y >= N || maze[x][y]=='+') {
            return false;
        }
        return true;
    }
};