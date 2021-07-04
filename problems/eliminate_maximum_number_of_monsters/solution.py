class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        
        timetoreach = []
        for i in range(len(dist)):
            x = (dist[i] + speed[i]-1)//speed[i]
            timetoreach.append(x)
        timetoreach.sort()
        res = 0
        for i in range(len(dist)):
            if i>=timetoreach[i]:
                return res
            res+=1
        return res
                
            
            
            
            