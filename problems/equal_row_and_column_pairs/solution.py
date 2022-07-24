class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        gridt  = [[grid[j][i] for j in range(len(grid))] for i in range(len(grid[0]))]
        n = len(grid)
        c = 0
        for row in grid:
            for col in gridt:
                if row==col:
                    c+=1
        return c