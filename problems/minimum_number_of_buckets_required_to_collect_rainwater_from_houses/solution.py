class Solution:
    def minimumBuckets(self, s: str) -> int:
        n = len(s)
        if n==1:
            if s[0]=='.':
                return 0
            else:
                return -1
        if n==2:
            if s[0]=='.':
                if s[1]=='.':
                    return 0
                else:
                    return 1
            else:
                if s[1]=='.':
                    return 1
                else:
                    return -1
        
        z = [0]*(n)
        ans = 0
        for i,v in enumerate(s):
            if v=='H':
                x = i-1
                y = i+1
                f = 0
                already = 0
                if x>=0:
                    if s[x]=='.':
                        f = 1
                        if z[x]==1:
                            already = 1
                            continue
                        z[x] = 1
                        
                if y<n:
                    if s[y]=='.':
                        f = 1
                        z[y] = 1
                
                if f:
                    if not already:
                        ans = ans +1
                else:
                    return -1
        return ans
                        
        