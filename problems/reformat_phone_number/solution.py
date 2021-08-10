class Solution:
    def reformatNumber(self, s: str) -> str:
        s = s.replace('-','')
        s = s.replace(' ','')
        n = len(s)
        if (n-4)%3==0:
            ans = ''
            for i in range(n-4):
                ans = ans + s[i]
                if (i+1)%3==0:
                    ans = ans + '-'
            for i in range(n-4,n):
                ans = ans + s[i]
                if i==(n-3):
                    ans = ans + '-'
            return ans
        else:
            ans = ''
            for i in range(n):
                ans = ans + s[i]
                if (i+1)%3==0:
                    ans = ans + '-'
            if n%3==0:
                return ans[:-1]
            else:
                return ans