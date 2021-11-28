class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        
        n = len(nums)
        ans = []
        for i in range(n):
            if nums[i]==target:
                ans.append(i)
        return ans