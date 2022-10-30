class Solution:
    def mostPopularCreator(self, cr: List[str], ids: List[str], v: List[int]) -> List[List[str]]:
        fre = {}
        n = len(cr)
        ma = 0
        for i in range(n):
            if cr[i] in fre:
                fre[cr[i]] += v[i]
            else:
                fre[cr[i]] = v[i]
            ma = max(ma , fre[cr[i]])
    
        high = set()  # creaters with highest freq
        for f in fre:
            if fre[f]==ma: high.add(f)
        
        maxView = {}
        ans = []
        for i in range(n):
            if cr[i] in high:
                if cr[i] in maxView:
                    if maxView[cr[i]][0] < v[i]:      # updating max views
                        maxView[cr[i]] = [v[i], ids[i]]
                    elif maxView[cr[i]][0]==v[i]:
                        if maxView[cr[i]][1] > ids[i]:  # lexo graphic smallest id
                            maxView[cr[i]] = [v[i], ids[i]]
                else:
                    maxView[cr[i]] = [v[i] , ids[i]]
        
        for c in maxView:
            ans.append([c, maxView[c][1]])
        return ans
            