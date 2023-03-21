// approach 1 : bfs with vis 
// approach 2 : choose every point in matrix as ideal point, brute force
// approach 3: median across row & col

class Solution 
{
public:
    int minTotalDistance(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        
        // [1] collect sorted indices/coords for each dimension 
        vector<int> xs, ys;
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    xs.push_back(i);
        
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                if (grid[i][j] == 1)
                    ys.push_back(j);
        
        // [2] extraction of median value is trivial, bcz xs and xy are sorted
        int x = xs[xs.size()/2];
        int y = ys[ys.size()/2];

        // [3] compute sum of distances between each point and meeting point;
        //    note that, for Manhattan distance, the final result is the  
        //    sum of individual distances for each dimension
        int d = 0;
        for (auto xx : xs) d += abs(x-xx);
        for (auto yy : ys) d += abs(y-yy);
        
        return d;
    }
};
