class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        
        n = len(nums)
        c = 0
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    if nums[j] - nums[i] == diff and nums[k] - nums[j] == diff:
                        c+=1
        return c