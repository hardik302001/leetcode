class Solution:
    def countGoodNumbers(self, n: int) -> int:
        e = (n+1)//2
        o = n//2
        m = 1000000007
        ans1 = pow(5,e,m)
        ans2 = pow(4,o,m)
        ans = (ans1 * ans2)%m
        return ans