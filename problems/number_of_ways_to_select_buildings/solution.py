class Solution:
    def numberOfWays(self, s: str) -> int:
        n = len(s)
        zl = [0]*(n+1)
        zl[1] = int(s[0]=='0')
        for i in range(1, n):
            if s[i]=='0':
                zl[i+1] = zl[i]+1
            else:
                zl[i+1] = zl[i]
        
        ol = [0]*(n+1)
        ol[1] = int(s[0]=='1')
        for i in range(1, n):
            if s[i]=='1':
                ol[i+1] = ol[i]+1
            else:
                ol[i+1] = ol[i]
        
        zr = [0]*(n)
        
        zr[-2] = int(s[-1]=='0')
        for i in range(n-2 , - 1, -1):
            if s[i]=='0':
                zr[i-1] = zr[i]+1
            else:
                zr[i-1] = zr[i]
        zr[-1] = 0
        orr = [0]*(n)
        orr[-2] = int(s[-1]=='1')
        for i in range(n-2 , - 1, -1):
            if s[i]=='1':
                orr[i-1] = orr[i]+1
            else:
                orr[i-1] = orr[i]
        orr[-1] = 0
#         print(zl[:n])
#         print(zr[:n])

#         print(orr[:n])
#         print(ol[:n])
        
        
        
        c = 0
        for i in range(1 , n-1):
            if s[i]=='1':
                c+= zl[i]*zr[i]
            else:
                c+=ol[i]*orr[i]
        return c
        