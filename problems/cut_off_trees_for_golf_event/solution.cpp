// Logical Thinking
// Since we always cut off the tree with lowest height first, we collect all trees and sort them by heights.
// If we make sure we walk the minimum steps to cut off each tree, the sum of these minimum steps will be the final answer.
// For cutting each tree (aimX, aimY), we implement BFS once:
// Start point: (curX, curY)
// Aim point: (aimX, aimY)
// End point: (aimX, aimY) or we have no way out.
// Transition: we try advancing by one step in 4 directions.


// The solution has two steps:

// 1) Sort tree positions based on tree height; 
// 2) BFS to find shortest path between two points; 
// The end point of current path is the starting point of next path. Priority_queue also works, but may be slower than simple sort due to both push and pop operations.

// The run time is up to O(m^2 n^2) where m and n is the matrix size.

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        // get all the tree positions and sort based on height
        // trees[i][0] is height. The default comparison of vector compare first element before other elements.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0;
        int  cur_row = 0, cur_col = 0;
        // accumulate all the paths
        for (int i = 0; i < trees.size(); i++) {
            int step = bfs(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
            // if next tree cannot be reached, step = -1;
            if (step == -1) return -1;
            ans += step;
            cur_row = trees[i][1];
            cur_col = trees[i][2];
        }
        return ans;
    }
    

    // BFS to find shortest path to next tree; if cannot reach next tree, return -1
    int bfs(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc}); 
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<int> dirx = {-1, 0, 1, 0};
        vector<int> diry = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                if (row == er && col == ec) return step;
                
                
                for (int i = 0; i < 4; i++) {
                    int newr = row + dirx[i];
                    int newc = col + diry[i];
                    if (newr < 0 || newr >= m || newc < 0 || newc >= n || visited[newr][newc] == 1 || forest[newr][newc] == 0){
                        continue;
                    }            
                    
                    q.push({newr, newc});
                    visited[newr][newc] = 1;
                    
                }
            }
            step++;
        }
        
        return -1;
    }
};
