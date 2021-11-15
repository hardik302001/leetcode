// Loop through grid and calculate surface area of the each cell. Also we deduct the common area betwen
// 2 consicuitive cells. We can consider only left and upper cell and multiply the common area by 2. Common
// area between consicuitive cell is the min height between them.

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int area = 0;
        int deduct = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
                    area = area +  2*(1+ grid[i][j] *2);                    
                }
                
                if(i)deduct += min(grid[i][j],grid[i-1][j]) * 2;  //bcz adjacent, so we cant see any of them
                if(j)deduct += min(grid[i][j],grid[i][j-1]) * 2;                
            }
        }
        
        return area - deduct;
    }
};