class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    
    // Out of bound check + Empty cell
    bool isValid(int row, int col, int m, int n, vector<vector<int>>& maze) {
        return row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == 0;
    }
    // BFS
    // TC: O(MN)
    // SC: O(MN)
    bool bfs(vector<int> start, vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int>& dst) {
        queue<vector<int>> q;
        q.emplace(start);
        // mark the current start point as visited
        visited[start[0]][start[1]] = true;
            
        
        while(!q.empty()) {
            auto start = q.front();
            q.pop();
            
            // target reached
            if(start == dst)
                return true;
            // From the current start point, explore moving in all 4 directions
            for(auto [dx, dy]: directions) {
                int row = start[0] + dx, col = start[1] + dy;
                // Move till we don't hit a wall
                while(isValid(row, col, maze.size(), maze[0].size(), maze))
                    row += dx, col += dy;
                // Now that a wall has been hit, retrack a step back to get to an empty cell
                row -= dx, col -= dy;
                // Now we are at a cell in a stopped state i.e not moving. We can change the direction from here
                if(!visited[row][col]){
                    q.emplace(vector<int>{row, col});
                    visited[row][col] = true;
                }
            }
        }
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
    
        // return dfs(start, maze, visited, destination);
        return bfs(start, maze, visited, destination);
    }
};