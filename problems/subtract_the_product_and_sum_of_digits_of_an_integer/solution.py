class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product = 1
        sums = 0
        for x in str(n):
            digit = int(x)
            product *= digit
            sums += digit
            
        return product - sums