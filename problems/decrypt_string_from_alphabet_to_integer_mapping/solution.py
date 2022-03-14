class Solution:
    def freqAlphabets(self, s: str) -> str:
        alp = 'abcdefghijklmnopqrstuvwxyz'
        ans = ''
        n = len(s)
        i = n-1
        while i>=0:
            if s[i]=='#':
                p = s[i-2] + s[i-1]
                ans+=chr(ord('a') + int(p) -1)
                i-=3
            else:
                ans+= chr(ord('a') + int(s[i]) -1)
                i-=1
        return ans[::-1]