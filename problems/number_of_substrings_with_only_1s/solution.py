class Solution:
    def numSub(self, s: str) -> int:
        s+=("0")
        l = []
        c = 0
        for i in s:
            if i=="1":
                c+=1
            else:
                if c>0:
                    l.append(c)
                c = 0
        
        
        res = 0
        for i in l:
            res += (i)*(i+1)//2
        
        
        
        return res%1000000007