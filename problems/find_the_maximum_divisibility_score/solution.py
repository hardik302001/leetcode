class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        divisors.sort()
        cc = -1
        ans = -1
        for i in divisors:
            c = 0
            for j in nums:
                if j%i==0:
                    c+=1
            if c>cc:
                cc = c
                ans = i
        return ans