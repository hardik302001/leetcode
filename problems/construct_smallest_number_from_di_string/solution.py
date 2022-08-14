
# count D's, reverse in size of (count+1)

class Solution:
    def smallestNumber(self, pat: str) -> str:
        n = len(pat)
        p = [i+1 for i in range(n+1)]
        
        ans = ''
        i = n-1
        while i>=0:
            ii = i
            f = 0
            while ii>=0 and pat[ii]=='D':
                ii-=1   
                f = 1
                
            if not f:
                i-=1
            else:
                p[ii+1:i+2] = p[ii+1:i+2][::-1]
                i = ii-1
          
        return ''.join(map(str, p))
    
    
 