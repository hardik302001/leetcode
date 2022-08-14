class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        
        ans = []
        
        for i in range(1, m-1):
            l = []
            for j in range(1, n-1):
                ma = max(grid[i][j], grid[i-1][j] , grid[i+1][j] ,grid[i][j+1],grid[i][j-1], grid[i-1][j-1], grid[i-1][j+1], grid[i+1][j-1] , grid[i+1][j+1] )
                l.append(ma)
            ans.append(l)
        return ans