class Solution:
    def sumOfDigits(self, nums: List[int]) -> int:
        return 1 - sum(list(map (int , (str(min(nums))))))&1