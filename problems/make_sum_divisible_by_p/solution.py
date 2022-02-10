# see WA's , I wasn't able to understand the solution

# we want to minimise the subarray length, so always update the d[key] to current index, then only we will get smaller length of subaray
# see https://leetcode.com/problems/subarray-sum-equals-k/


class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        tot = sum(nums)
        rem  = tot%p
        if rem==0:
            return 0
        
        #   now our target is to remove min length subarray such that its sum is rem
        
        min_len = n         #in worst  case we need to remove whole array
        d = {}
        d[0] = -1
        summ = 0
        end = -1
        for i , v in enumerate(nums):
            summ = summ + v
            summ = summ %p
            
            if (summ - rem)%p in d:
                sz = i - d[(summ - rem)%p]     
                if sz<min_len:
                    min_len = sz
                    end = i
        
            d[summ] = i        # adding key to map
        
        
        if min_len==n:
            return -1
        else:
            remove = nums[end-min_len+1:end+1]
            rem_sum = sum(remove)
            # print(remove)

            return min_len if (tot-rem_sum)%p==0 else -1