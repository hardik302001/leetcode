class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        p = [i*i for i in sorted(nums, key = lambda x: abs(x))]
        return p