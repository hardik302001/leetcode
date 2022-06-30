# meet at median

class Solution:
    def minMoves2(self, l: List[int]) -> int:
        l.sort()
        n = len(l)

        mid = l[n//2]
        ans = 0
        for i in range(n):
            ans+= abs(l[i]-mid)
        
        return ans