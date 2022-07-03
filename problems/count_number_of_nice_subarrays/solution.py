# problem is same as subarray sum equals k
# https://leetcode.com/problems/subarray-sum-equals-k/

# just convert nums[i] = 0, if even 
# else
# nums[i] = 1

# now ques is exactly same as: https://leetcode.com/problems/binary-subarrays-with-sum/
# now ques is exactly same as suabrray sum k (where k is odd count)



class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        
        n = len(nums)
        for i in range(n):
            nums[i] = nums[i]%2
        
        d = {}
        d[0] = 1
        s = 0
        count = 0
        for i in range(len(nums)):
            s += nums[i]
            if s-k in d: # --- I
                count += d[s-k]
               # or return True
               # or return indicies

               # add sum to frq dict
            if s in d:
                d[s] += 1 # --- II
            else:
                d[s] = 1
        return count

        
        
        
        
