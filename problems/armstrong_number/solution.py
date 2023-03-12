class Solution:
    def isArmstrong(self, n: int) -> bool:
        nums = list(str(n))
        total = 0
        k = len(nums)        
        for num in nums:
            total += (int(num)**k)
        return total == n