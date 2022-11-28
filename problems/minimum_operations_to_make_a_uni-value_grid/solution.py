class Solution:
    def minOperations(self, grid: List[List[int]], k: int) -> int:
        s = 0
        l = []
        for i in grid:
            l.extend(i)
            s = s+ sum(i)
        m = len(grid)
        n = len(grid[0])
        l.sort()
        p = l.copy()
       
        sz = m*n
       
        mid = l[sz//2]
        ans1 = 0
        for i in range(sz):
            if l[i]<mid:
                c = (mid-l[i])//k
                ans1 = ans1 + c
                l[i] = l[i] + c*k
            elif l[i]>mid:
                c = (l[i]-mid)//k
                ans1 = ans1 +c
                l[i] = l[i]-c*k
        if len(set(l))!=1:
            ans1 = -1
                
       
        return ans1