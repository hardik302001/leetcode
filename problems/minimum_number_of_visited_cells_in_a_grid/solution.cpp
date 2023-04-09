// Approach
// Easy Simple BFS with a reverse loop to avoid TLE.
// Checking the farthest points first will lead to a quicker path.

class Solution {
public:
      int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0, 0});
        vis[0][0] = 1;
        int steps = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [i, j] = q.front();
                q.pop();
                if(i == n-1 and j == m-1) return steps;
                if(grid[i][j] == 0) continue;

                //reverse loop to check the farthest point first
                for(int k=grid[i][j] + j; k >= j+1; k--){   
                    if(k < 0 or k >= m or vis[i][k]) continue;
                    q.push({i, k});
                    vis[i][k] = 1;
                }

                for(int k=grid[i][j] + i; k >= i+1; k--){
                    if(k < 0 or k >= n or vis[k][j]) continue;
                    q.push({k, j});
                    vis[k][j] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};