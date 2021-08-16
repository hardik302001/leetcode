class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d = {}
        for i in text:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        m = 10000000
        t = 'balon'
        for i in t:
            if i in d:
                if i=='b' or i=='a' or i=='n':
                    m = min(m, d[i])
                elif i=='l' or i=='o':m = min(m, d[i]//2)
            else: return 0  #bcz key in not present in d
        return m