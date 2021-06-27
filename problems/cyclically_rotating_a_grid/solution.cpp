class Solution {

    int m, n;

    

    void assign(vector<vector<int>>& grid, int l, vector<int>& v, int start) {

        // top row

        for(int i = l; i < n - l - 1; ++i)

            grid[l][i] = v[start++];

        // right

        for(int i = l; i < m - l - 1; ++i)

           grid[i][n - l - 1] = v[start++];

        // bottom row

        for(int i = n - l - 1; i > l; --i)

            grid[m - l - 1][i] = v[start++];

        // left

        for(int i = m - l - 1; i > l; --i)

            grid[i][l] = v[start++];

    }

public:

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        m = grid.size();

        n = grid[0].size();

        int ll = min(m, n) / 2; // number of cycles

        

        for(int l = 0; l < ll; ++l) {

            vector<int> v;

            

            // top row

            for(int i = l; i < n - l - 1; ++i)

                v.push_back(grid[l][i]);

            

            // right

            for(int i = l; i < m - l - 1; ++i)

                v.push_back(grid[i][n - l - 1]);

        

            // bottom row

            for(int i = n - l - 1; i > l; --i)

                v.push_back(grid[m - l - 1][i]);

            

            // left

            for(int i = m - l - 1; i > l; --i)

                v.push_back(grid[i][l]);

           

            // rotate

            int kk = k % v.size();

            for(int i = 0; i < kk; ++i)

                v.push_back(v[i]);

            

            // assign it back to the grid

            assign(grid, l, v, kk);

        }

        

        return grid;

    }

};
        

