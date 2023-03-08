class Solution:
    def validSubarraySplit(self, nums):
        n = len(nums)

        dp = [float("inf")]*(n+1)

        dp[0] = 0

        for i in range(1,n+1):
            for j in range(i):
                if math.gcd(nums[i-1],nums[j]) > 1:
                    dp[i] = min(dp[i],dp[j] + 1)

        return dp[-1] if dp[-1] != float("inf") else -1
