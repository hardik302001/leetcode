/*

Since each day, the new cell becomes flooded with water, so if on i th day, we can't walk from the top to bottom then all days after i th we also can't walk.
So we can Binary Search to find the last day we can walk in range [1..len(cells)], for each mid = (left + right)/2), we need to check if we can still walk in mid th day.
How to check if we can walk in dayAt th day?
Firstly, we build the grid in the dayAt th day
Then we use BFS to check if we can reach to the any cells in bottom row by starting from any cells in top row.

*/


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int left = 1, right = cells.size(), ans = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canWalk(cells, row, col, mid)) {
                ans = mid; // Update current answer so far
                left = mid + 1; // Try to find a larger day
            } else right = mid; // Try to find a smaller day
        }
        return ans;
        
    }

        bool canWalk(vector<vector<int>>& cells, int M, int N, int dayAt) {
            vector<vector<int>> mat(M, vector<int>(N, 0)); // Create grid in the `dayAt` th date
            
            for (int i = 0; i < dayAt; ++i){ 
                mat[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            
            
            queue<pair<int, int>> todo;
            vector<int> dx = {-1, 0,1, 0};
            vector<int>dy = {0,1,0,-1};

            for(int j=0;j<N;j++){   //first row
                if( mat[0][j]==0){
                    todo.push({0,j});
                    mat[0][j] = 1;
                }
                
            }

            while (!todo.empty()) {
                int curx = todo.front().first;
                int cury = todo.front().second;

                todo.pop();
                if(border(curx,cury,M,N)){
                    return true;
                }
                for(int i = 0;i<4;i++){
                    int newx = curx + dx[i];
                    int newy = cury + dy[i];

                    if(inside(newx , newy , M , N , mat) and mat[newx][newy]==0){
                        todo.push({newx, newy});
                        mat[newx][newy] = 1;  
                        
                    }

                }   

            }


            return false;

        }





         bool inside(int x, int y, int &M, int &N, vector<vector<int> > &mat) {
            if ((x < 0 || x >= M || y < 0 || y >= N )) {
                return false;
            }
            return true;
        }
        
        
        bool border(int x, int y, int &M, int &N) {
            return (x == M-1);
        }

    
};