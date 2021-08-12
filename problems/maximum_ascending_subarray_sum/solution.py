class Solution:
    def maxAscendingSum(self, nu: List[int]) -> int:
        m = []
        n = len(nu)
        c = 0
        for i in range(1,n):
            if nu[i]>nu[i-1]:
                c = c + nu[i-1]
            else:
                c = c + nu[i-1]
                m.append(c)
                c = 0
        c = c + nu[-1]
        m.append(c)
        return max(m)