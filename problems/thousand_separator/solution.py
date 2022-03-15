class Solution:
    def thousandSeparator(self, n: int) -> str:
        n = str(n)
        n = n[::-1]
        p = ''
        for i in range(len(n)):
            p+=n[i]
            if i%3==2:
                p+='.'
        p = p [::-1]
        
        # print(p)
        if p[0]=='.':
            return p[1:]
        return p