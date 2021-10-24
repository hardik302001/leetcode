class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def check(n):
            f = 0
            n = str(n)
            s = set(n)
            f = 1
            for i in s:
                if n.count(i)!=int(i):
                    f = 0
            if f:
                return True
            else:
                return False
        
        x = n+1
        while True:
            if check(x):
                return x
            else:
                x = x +1
                
                