class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        d = {}
        for dom in dominoes:
            dom.sort()
            dom = tuple(dom)
            if dom in d:
                d[dom]+=1
            else:
                d[dom] = 1
        c = 0
        for i in d:
            c+= (d[i])*(d[i]-1)//2
        return c