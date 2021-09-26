class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        m = len(grid[0])
        a = grid[0]
        b = grid[1]
        p1 = [0]*(m+1)
        p2 = [0]*(m+1)
        for i in range(1,m+1):
            p1[i] = p1[i-1] + a[i-1]
            p2[i] = p2[i-1] + b[i-1]
        # print(p1)
        # print(p2)
        pp = []
        for i in range(1,m+1):
            # print(p1[m]-p1[i] , p2[i-1])
            pp.append(max(p1[m] - p1[i], p2[i-1]))
        return (min(pp))