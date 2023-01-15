class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        s1 = sum(nums)
        s2 = 0
        for i in nums:
            while i>0:
                s2+=i%10
                i//=10
        return abs(s1-s2)