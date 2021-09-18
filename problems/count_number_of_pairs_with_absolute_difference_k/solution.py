class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        c = 0
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                if abs(nums[i]-nums[j])==k:
                    c =c  +1
        return c