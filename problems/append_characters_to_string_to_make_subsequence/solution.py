class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        i = 0
        j = 0
        n = len(s)
        m = len(t)
        
        
        while True:
            if i>=n:
                break
            if j>=m:
                return 0
            if s[i]==t[j]:
                j+=1
            i+=1
        return m-j