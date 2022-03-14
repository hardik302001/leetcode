class Solution:
    def modifyString(self, s: str) -> str:
        n = len(s)
        if n==1:
            if s[0]=='?':
                return 'a'
            else: 
                return s
        p = {'a','b','c'}
        ans = list(s)
        if s[0]=='?':
            poss = list(p-{ans[1]})[0]
            ans[0] = poss
        if s[-1]=='?':
            poss = list(p-{ans[-2]})[0]
            ans[-1] = poss
        
        for i in range(1 , n-1):
            if s[i]!='?':
                ans[i] = s[i]
            else:
                poss = list(p-{ans[i-1],ans[i+1]})[0]
                ans[i] = poss
        return ''.join(ans)