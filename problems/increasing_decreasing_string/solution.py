class Solution:
    def sortString(self, s: str) -> str:
        d = {}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i] =1 
        k = sorted(d.keys())  # this is a list of sorted keys
        
        ans = ""
        
        while len(ans)!=len(s):
            for i in k:
                if d[i]>0:
                    d[i]-=1
                    ans = ans + i
                    
            for i in k[::-1]:
                if d[i]>0:
                    d[i]-=1
                    ans= ans + i
        
        
        
        return ans