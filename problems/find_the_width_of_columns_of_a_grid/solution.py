class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        ans = []

        m = len(grid)
        n = len(grid[0])
        for i in range(n):
            ma = 0
            for j in range(m):
                cur = grid[j][i]
                ma = max(len(str(cur)), ma)
            ans.append(ma)
        return ans
