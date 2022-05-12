class Solution:
    def reformat(self, s):
        p = []
        q = []
        for i in s:
            if 'a'<=i<='z':
                p.append(i)
            else:
                q.append(i)
        if len(p)==len(q):
            ans = ''
            for i in range(len(p)):
                ans+=p[i]
                ans+=q[i]
            return ans
        elif len(p)==len(q)+1:
            ans = ''
            for i in range(len(q)):
                ans+=p[i]
                ans+=q[i]
            ans+=p[-1]

            return ans
            
            
        elif len(p)+1==len(q):
            ans = ''
            for i in range(len(p)):
                ans+=q[i]
                ans+=p[i]
            ans+= q[-1]

            return ans

        else:
            return ""