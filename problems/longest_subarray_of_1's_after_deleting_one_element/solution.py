class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        l = 0
        ans = 0 #bcz we can replace atleast one 1
        d = Counter()
        n = len(nums)
        
        for r in range(n):
            d[nums[r]]+=1
            
            while(r-l+1 - d[1]>1):
                d[nums[l]]-=1
                l+=1
            
            ans = max(ans , r-l+1)
            
                
        return ans-1   #bcz u have to delete 1 element