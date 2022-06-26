class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        i = 0
        for row in grid:
            if row[i]==0 or row[n-1-i]==0:
                return False
            for j in range(n):
                if j==i or j==n-1-i:
                    continue
                else:
                    if row[j]!=0:
                        return False
            i+=1
        return True