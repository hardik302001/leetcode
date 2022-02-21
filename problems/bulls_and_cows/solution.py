class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bull, cow = 0, 0
        s = Counter() # secret hashtable
        g = Counter() # guess hashtable
        
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bull += 1
            else:
                s[secret[i]] += + 1
                g[guess[i]] += + 1
        
        for k in s:
            if k in g:
                cow += min(s[k], g[k])
        
        return '{0}A{1}B'.format(bull, cow)
