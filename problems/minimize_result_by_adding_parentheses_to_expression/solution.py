class Solution:
    def minimizeResult(self, s: str) -> str:
        def solve(exp):
            
            p = exp.index('+')
            x1 = 0
            x2 = 0
            f = exp.index('(')
            g = exp.index(')')
            ans = eval(exp[f:g+1])
            
            
            return (int(exp[:f]) if len(exp[:f]) else 1)*(int(exp[g+1:] if len(exp[g+1:]) else 1) * ans)
                    
                
        
        
        p = s.index('+')
        n = len(s)
        res = ''
        ma = 100000000000000
        for i in range(p):
            for j in range(p+2 , n+1):
                exp = s[:i] + '(' + s[i:p] +s[p]+ s[p+1:j] + ')' + s[j:]
                ans = solve(exp)
            
                if ans<ma:
                    res = exp
                    ma = ans
        # print(ma)
        return res