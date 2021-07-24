class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        d = {}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        a = d.values()
        if len(set(a))==1:
            return True
        return False