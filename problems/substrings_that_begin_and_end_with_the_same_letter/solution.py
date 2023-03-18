class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        d = Counter(s)
        ans = 0
        for i in d:
            x = d[i]
            ans += x*(x-1)//2 +x
        return ans