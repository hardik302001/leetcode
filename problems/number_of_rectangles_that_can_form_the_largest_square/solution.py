class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        d = {}
        for i in rectangles:
            a = i[0]
            b = i[1]
            m = min(a,b)
            if m in d:
                d[m] = d[m] +1
            else:
                d[m] = 1
        x = max(d.keys())
        return d[x]