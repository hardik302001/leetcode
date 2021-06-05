class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n));  //declaring a 2d matrix(n*n)
        int m = n;
        int x0 = 0, x1 = m - 1; // vertical
        int y0 = 0, y1 = n - 1; // horizon
        int k = 1;
        while(x0 <= x1 && y0 <= y1) {    
            // travel right side
            for (int j = y0; j <= y1; ++j)
                ans[x0][j] = k++;
            x0++;
            
            // travel down side
            for (int i = x0; i <= x1; ++i)
                ans[i][y1] = k++;
            y1--;
            
            if (x0 > x1) break;
            // travel left side
            for (int j = y1; j >= y0; --j) 
                ans[x1][j] = k++;
            x1--;
            
            if (y0 > y1) break;
            // travel up side
            for (int i = x1; i >= x0; --i)
                ans[i][y0] = k++;
            y0++;
        }
        
        return ans;
    }
    
};