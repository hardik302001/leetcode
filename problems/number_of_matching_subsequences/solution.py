class Solution:

    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        def isubseq(s,p):
            i = 0
            j = 0
            ls = len(s)
            lp = len(p)
            while ls and lp:
                if s[i]==p[j]:
                    i = i +1
                    j = j + 1
                    lp = lp -1
                    ls = ls -1
                else:
                    i = i +1
                    ls = ls -1
            if j==len(p):
                return True
            return False
        c = 0
        
        d = {}
        for i in words:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
                
        for i in d:
            if(isubseq(s,i)):
                c = c+d[i]
        return c