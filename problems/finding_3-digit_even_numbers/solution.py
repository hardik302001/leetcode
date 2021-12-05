class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        n = len(digits)
        e = []
        o = []
        s = set()
        for i in digits:
            if i&1:o.append(i)
            else:e.append(i)
        
        for i in range(len(o)):
            for j in range(len(o)):
                for k in range(len(e)):
                    if i!=j:
                        p= 100*(o[i]) + 10*(o[j]) + (e[k])
                        s.add(p)
        for i in range(len(o)):
            for j in range(len(e)):
                for k in range(len(e)):
                    if j!=k:
                        p= 100*(o[i]) + 10*(e[j]) + (e[k])
                        s.add(p)
        for i in range(len(e)):
            for j in range(len(o)):
                for k in range(len(e)):
                    if i!=k:
                        if e[i]!=0:
                            p= 100*(e[i]) + 10*(o[j]) + (e[k])
                            s.add(p)
                            
        for i in range(len(e)):
            for j in range(len(e)):
                for k in range(len(e)):
                    if i!=j and j!=k and k!=i:
                        if e[i]!=0:
                            p= 100*(e[i]) + 10*(e[j]) +(e[k])
                            s.add(p)
        l = list(s)
        l.sort()
        return l

                
                        