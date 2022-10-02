class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            p = grid[i]
            for j in range(1, n):
                grid[i][j] = grid[i][j-1] + grid[i][j]
    
        ans = 0
        for i in range(m):
            for j in range(n):
                center = grid[i][j] -  grid[i][j-1]
                if i-1>=0 and i+1<m and j-1>=0 and j+1<n:
                    if j-1==0:
                        prevup = 0
                        prevbelow = 0 
                    else:
                        prevbelow = grid[i+1][j-2]
                        prevup = grid[i-1][j-2]
               
                    up = grid[i-1][j+1] - prevup
                    down = grid[i+1][j+1] - prevbelow
                    
                    ans = max( ans , center + up + down)
        return ans