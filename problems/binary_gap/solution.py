class Solution:
    def binaryGap(self, n: int) -> int:
        m = 0
        i = 0
        prev = -1
        
        while n:
            top = n&1
            if top:
                if prev != -1:
                    m = max(m , i - prev)
                prev = i
            n = n>>1 
            i =  i + 1
            # print(n)
        return m
            