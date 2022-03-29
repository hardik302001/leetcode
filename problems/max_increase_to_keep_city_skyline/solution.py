class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        row_maxes = [max(row) for row in grid]

        col_maxes = []
        for colIdx in range(len(grid[0])):
            col = [grid[row][colIdx] for row in range(len(grid))]
            col_maxes.append(max(col))

        increases = 0
        for idx, row in enumerate(grid):
            for jdx, height in enumerate(row):
                increases += min(row_maxes[idx], col_maxes[jdx]) - height
        return increases