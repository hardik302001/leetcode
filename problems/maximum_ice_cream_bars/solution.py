class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        c  = 0
        s = 0
        n = len(costs)
        while c<n and s + costs[c] <=coins:
            s = s + costs[c]
            c = c + 1
            
        return c