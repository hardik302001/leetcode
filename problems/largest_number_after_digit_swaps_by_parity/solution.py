class Solution:
    def largestInteger(self, num: int) -> int:
        o = []
        e = []

        num = str(num)
        p = [-1]*(len(num))
        for i in range(len(num)):
            if int(num[i])&1:
                o.append(num[i] )
                p[i] = 0
            else:
                e.append(num[i])
                p[i] = 1
        o.sort()
        e.sort()
        
        ans = ''
        for i in range(len(num)):
            if p[i]==0:
                ans+=o.pop() 
            else:
                ans+=e.pop()
     
        return int(ans)