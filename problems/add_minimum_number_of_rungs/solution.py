class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        
        diff = []
        rungs = [0] + rungs
        ans = 0
        # print(rungs)
        for i in range(1, len(rungs)):
            x = rungs[i] - rungs[i-1]
            if x> dist:
                # p = 0
                # y = 0
                # while rungs[i-1] + dist + y<rungs[i]:
                #     p = p +1
                #     y = y + dist
                # ans = ans+ p
                
                p = (x - dist +dist -1) //dist
                ans = ans+ p
        
            
        return ans