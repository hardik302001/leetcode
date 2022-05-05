class Solution:
    def minimumCardPickup(self, s: List[int]) -> int:
        d = Counter()
        l = 0
        n = len(s)
        ans = 10000000000
        for r in range(n):
            d[s[r]]+=1
            while d[s[r]]>1:
                ans = min(ans , r-l+1)
                d[s[l]]-=1
                l+=1
        print(ans)
        return -1 if ans==10000000000 else ans