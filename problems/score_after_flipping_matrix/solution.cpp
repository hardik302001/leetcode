class Solution {
public:
    void flipRow(vector<vector<int>>& grid, int row, int m){
        for(int j=0;j<m;j++)
            grid[row][j] = !grid[row][j]; 
    }
    
    void flipCol(vector<vector<int>>& grid, int col, int n){
        for(int i=0;i<n;i++) 
            grid[i][col] = !grid[i][col]; 
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        //if any row starts with 0 flip it, to get the most significant bit as 1
        for(int i=0;i<n;i++){
            if(grid[i][0] == 0) 
                flipRow(grid, i, m);
        }
        
        //if in a column the count of zero if more than of ones, flip it.
        int cz, co;
        for(int j=0;j<m;j++){
            cz = 0, co = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j] == 0) cz++;
                else co++;
            }
            if(cz > co) 
                flipCol(grid, j, n);
        }
        
        //get the sum
        int sum = 0, p;
        for(int i=0;i<n;i++){
            p = 0;
            for(int j=m-1;j>=0;j--) 
                //Note: converting from binary to decimal
                sum += grid[i][j]*pow(2, p++);
        }
        
        return sum;
    }
};