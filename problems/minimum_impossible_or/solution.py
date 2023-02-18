# if we have all powers of 2 uptil 2power p , we can make all numbers till 2power (p+1)
# if we have [1 ,2 ,4] , we can make all numbers till 7

# so we check for minimum power of 2 that doesnot exist in nums

class Solution:
    def minImpossibleOR(self, nums: List[int]) -> int:
        s = set(nums)
        for i in range(0 , 40):
            x = 2**i
            if x not in s:
                return x
        return 2
            