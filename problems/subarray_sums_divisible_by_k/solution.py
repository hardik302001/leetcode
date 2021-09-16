#https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/310767/(Python)-Concise-Explanation-and-Proof
#also see subarray sum equal k

#see pepcoding video yt of subarray sum div by k




class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        d = {}
        d[0] = 1
        s = 0
        count = 0
        for i in range(len(nums)):
            s += nums[i]
            key = s%k
            
            if key in d:
                count = count + d[key]
                d[key] += 1 # --- II
            else:
                d[key] = 1
        return count
