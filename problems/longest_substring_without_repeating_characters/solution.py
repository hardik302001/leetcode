class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1:
            return 1
        amxi = 0
        l = 0
        r = 1
        while r < len(s):
            if s[r] not in s[l:r]:
                r += 1
                amxi = max(amxi, len(s[l:r]))
            else:
                while s[r] in s[l:r]:
                    l += 1
        return amxi