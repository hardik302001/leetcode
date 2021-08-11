class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        p = [0]*100
        for i in logs:
            for j in range(i[0],i[1]):
                p[j-1950]+=1
        m = max(p)
        i = p.index(m)
        return i+1950