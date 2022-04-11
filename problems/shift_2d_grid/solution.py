class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        l = []
        m = len(grid)
        n = len(grid[0])
        for row in grid:
            for el in row:
                l.append(el)
        
        k = k%(m*n)
        p = l[m*n-k:] + l[:m*n-k]
        # print(p)
        ans = []
        for i in range(0,m*n , n):
            ans.append(p[i:i+n])
       
        
        return ans