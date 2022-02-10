'''

Prefix hashmap O(N) - [Accepted]

Single scan. Given the current sum and the k, we check if (sum-k) existsed before at an earlier stage (at a smaller window size)


'''


'''
also see: https://www.tutorialspoint.com/maximum-size-subarray-sum-equals-k-in-cplusplus
also see: https://leetcode.com/problems/subarray-sums-divisible-by-k/
also see: https://leetcode.com/problems/continuous-subarray-sum/
'''

#for more context search subarray sum equals k on yputube and watch pepcoding videos
#also see : https://leetcode.com/problems/subarray-sums-divisible-by-k/



#here u want count, so d[0] = 1, the count of such subarrays
#if u wanted length as in https://www.tutorialspoint.com/maximum-size-subarray-sum-equals-k-in-cplusplus
#we say d[0] = -1, for index and update d[key] = i (index), rather we do d[i]+=1 in counting subarrays


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
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
