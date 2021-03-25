class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        d = {}
        n = len(s)
        for i in range(0,n):
            ss = s[i:i+10]
            if ss in d:
                d[ss]+=1
            else:
                d[ss] = 1
        print(d)
        a = []
        b = []
        for i in d:
            if d[i]>1:
                a.append(i)
            else:
                b.append(i)
        if len(a)>0:
            return a
        