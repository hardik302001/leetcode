class Solution:
    def bestClosingTime(self, cust: str) -> int:
        n = len(cust)
        op = []  # open till index i
        cl = []  # close after index i
        
        if cust=="N"*n:
            return 0
        if cust=="Y"*n:
            return n
        
        x = 0
        for i in range(n):
            if cust[i]=='Y':
                x+=0
            else:
                x+=1
            
            op.append(x)
        
        x = 0
        for i in range(n-1, - 1, -1):
            if cust[i]=='Y':
                x+=1
            else:
                x+=0
            
            cl.append(x)
        
        cl = cl[::-1]
        cl.append(0)   # closing at nth hour
        
        ans = 0
        val = cl[0]
        for i in range(1, n+1):
            s = cl[i] + op[i-1]
            
            if s<val:
                ans = i
                val = s
   
        return ans
