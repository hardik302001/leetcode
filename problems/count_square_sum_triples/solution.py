class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        s = set()
        for i in range(1,n+1):
            s.add(i*i)
        for i in s:
            for j in s:
                if i==j:
                    continue
                else:
                    tot= i+j
                    if tot in s:
                        ans = ans +1
        return ans