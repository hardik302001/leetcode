class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        id = -1
        prev = 0
        ans = -1
        
        for i,cur in logs:
            dif = cur-prev
            if dif>ans:
                id = i
                ans = dif
            elif dif==ans:      
                id = min(id, i)
            prev = cur
            
        return id