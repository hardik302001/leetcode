class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        p = []
        for i, v in enumerate(s):
            if v==c:
                p.append(i)
        
        ans = []
        n = len(s)
        x = 0
        for i in range(n):
            if x-1>=0:
                res = min(abs(p[x]-i), abs(p[x-1]-i))
            else:
                res = abs(p[x]-i)
            ans.append(res)
            if p[x]==i and x+1<len(p):
                x = x + 1
            # print(ans)
        return ans