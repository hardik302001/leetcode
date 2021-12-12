class Solution:
    def countPoints(self, rings: str) -> int:
        d = {}
        n = len(rings)
        for i in range(0,n,2):
            col = rings[i]
            num = int(rings[i+1])
            if num in d:
                d[num].add(col)
            else:
                d[num] = set()
                d[num].add(col)
        # print(d)
        c = 0
        for i in d:
            if len(d[i])==3:
                c = c +1
        return c