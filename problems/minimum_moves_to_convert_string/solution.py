class Solution:
    def minimumMoves(self, s: str) -> int:
        i = 0
        ans = 0
        while i<len(s):
            if s[i]=='O':
                i = i +1
            else:
                ans = ans + 1
                i = i + 3
        return ans