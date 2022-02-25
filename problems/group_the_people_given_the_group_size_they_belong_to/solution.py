class Solution:
    def groupThePeople(self, gs: List[int]) -> List[List[int]]:
        n = len(gs)
        d = {}
        for i in range(n):
            if gs[i] not in d:
                d[gs[i]] = []
            d[gs[i]].append(i)
        
        ans = []
        for i in d:
            l = d[i]
            
            while len(l):
                t = []
                while len(t)!=i:
                    t.append(l.pop())
                ans.append(t)
        return ans