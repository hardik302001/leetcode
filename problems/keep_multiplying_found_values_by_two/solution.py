class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        p =set(nums)
        while original in p:
            original = original * 2
        return original