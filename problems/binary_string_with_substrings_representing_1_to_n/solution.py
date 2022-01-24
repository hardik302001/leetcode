class Solution:
    def queryString(self, s: str, n: int) -> bool:
        mi = 1
        ma = len(bin(n)[2:])
        
        d = {}
        for size in range(mi , ma + 1):
            for j in range(len(s)):
                substr = s[j:j+size]
                num = int(substr, 2)
                if num in d:
                    d[num]+=1
                else:
                    d[num] = 1
        
        for i in range(1, n+1):
            if i not in d:
                return 0
        return 1