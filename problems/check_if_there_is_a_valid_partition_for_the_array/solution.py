class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        if n==2 : return (nums[1]==nums[0])
            
        
        dp = [False]*(n+1)
        dp[0] = True
        for i in range(1, n):
            if nums[i-1]==nums[i] and dp[i-1]:
                dp[i+1] = True
            if i-2>=0 and nums[i-2]==nums[i-1] and nums[i-1]==nums[i] and dp[i-2]:
                dp[i+1] = True
            if i-2>=0 and nums[i-1]-nums[i-2]==1 and nums[i]-nums[i-1]==1 and dp[i-2]:
                dp[i+1] = True
     
        return dp[n]