class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        d = {}
        l = 0
        ans = 0
        n = len(nums)
        s = 0
        
        for r in range(n):
            s+=nums[r]
            if nums[r] in d:
                d[nums[r]]+=1
            else:
                d[nums[r]] = 1
            
            while d[nums[r]]>1:
                s-=nums[l]
                d[nums[l]]-=1
                l+=1
            ans = max(ans , s)
        return ans