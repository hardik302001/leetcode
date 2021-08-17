class Solution:
    def mostCommonWord(self, s: str, banned: List[str]) -> str:
        s = s.replace('.',' ')
        s = s.replace('!',' ')
        s = s.replace('?',' ')
        s = s.replace(',',' ')
        s = s.replace(';',' ')
        s = s.replace("'",' ')
        s  = (s.split())
        p = []
        for i in s:
            p.append(i.lower())
        print(p)
        s = p
        d = {}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        d = sorted(d.items(), key = lambda x: -x[1])
        print(d)
        for i in d:
            if i[0] not in banned:
                return i[0]