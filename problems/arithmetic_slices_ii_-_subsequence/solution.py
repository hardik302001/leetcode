# also see lc 1027 and 413

class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        from collections import defaultdict
        ans = 0
        dp = [defaultdict(int) for item in nums]
        for i in range(len(nums)):
            for j in range(i):
                diff = nums[i] - nums[j]
                dp[i][diff] += 1
                if diff in dp[j]: # Check Key
                    dp[i][diff] += dp[j][diff]
                    ans += dp[j][diff]
        return ans