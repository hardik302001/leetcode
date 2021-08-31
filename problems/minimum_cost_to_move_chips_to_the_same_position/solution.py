class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        a = 0
        b = 0
        n = len(position)
        for i in range(n):
            if (position[i]&1):
                a = a + 1
            else:
                b = b + 1
        return min(a,b)
    