class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse = True)
        ans = 0
        n = len(cost)
        for i in range(n):
            if (i+1)%3==0:
                continue
            else:
                ans = ans + cost[i]
        return ans