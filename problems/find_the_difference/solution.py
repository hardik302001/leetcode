class Solution:
    def findTheDifference(self, s, t):
        ans = 0
        for c in s + t:
            ans ^= ord(c)
        return chr(ans)