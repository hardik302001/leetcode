class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        # def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        ans = []
        queue = deque([(0, *start)])
        grid[start[0]][start[1]] *= -1 
        while queue: 
            x, i, j = queue.popleft()
            if pricing[0] <= -grid[i][j] <= pricing[1]: ans.append((x, -grid[i][j], i, j))
            for ii, jj in (i-1, j), (i, j-1), (i, j+1), (i+1, j): 
                if 0 <= ii < m and 0 <= jj < n and grid[ii][jj] > 0: 
                    queue.append((x+1, ii, jj))
                    grid[ii][jj] *= -1
        return [[i, j] for _, _, i, j in sorted(ans)[:k]]