class Solution:
    def findPoisonedDuration(self, t: List[int], d: int) -> int:
        ans= 0
        for i in range(1, len(t)):
            x = t[i]-t[i-1]
            ans = ans + min(d, x)
        ans = ans + d
        return ans