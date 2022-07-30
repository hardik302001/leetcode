class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        p = []
        for x, y in points:
            p.append(x)
        p.sort()
        dif = 0
        ma = 0
        n = len(p)
        for i in range(1, n):
            dif = p[i]-p[i-1]
            ma = max(ma , dif)
        return ma