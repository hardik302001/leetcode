class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key = lambda x: x[0]-x[1])  # x[0]-x[1] is savings , if dif >0, choosing b is befeicial , dif<0 , choosimg a is better
        
        
        c = 0
        for i in range(len(costs)//2):
            c+= costs[i][0] + costs[i+len(costs)//2][1]
        return c
        
        