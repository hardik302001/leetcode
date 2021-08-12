class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        l = r = start
        while True:
            if l >= 0 and nums[l] == target: return start - l
            if r < len(nums) and nums[r] == target: return r - start
            l -= 1
            r += 1