class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        s= set()
        deg = [0]*100005
        for i in matches:
            deg[i[1]] +=1
            s.add(i[0])
            s.add(i[1])
        
        
        a1 = []
        a2 = []
        for i in s:
            if deg[i]==0:
                a1.append(i)
            elif deg[i]==1:
                a2.append(i)
        a1.sort()
        a2.sort()
        return [a1, a2]