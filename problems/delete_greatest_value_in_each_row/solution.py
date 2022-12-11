class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        s = 0
        for row in grid:
            row.sort()
        

        for i in range(len(grid[0])):
            m = 0
            for row in grid:
                 m = max(m , row[i])
            s += m
        
        
        return s