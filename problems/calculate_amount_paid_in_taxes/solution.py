class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ans = 0
        last = 0
        for i, j in brackets:
            dif = i-last
            last = i
            cur = min(income, dif)
            ans += cur*j/100
            income -= cur
        return ans