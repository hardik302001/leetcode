# similar to subarray sum equals k
# https://leetcode.com/problems/subarray-sum-equals-k/

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        d = {}
        d[0] = 1
        cur = 0
        ans = 0
        for i in nums:
            cur = cur^i
            if (cur^0) in d:   # bcz we want xor to be 0
                ans += d[cur]
            
            if cur in d:
                d[cur]+=1
            else:
                d[cur] = 1
        return ans