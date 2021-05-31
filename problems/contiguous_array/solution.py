class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        """
        The trick is to keep a running total, in the following way:
        adding 1 for each 1, and subtracting 1 for each zero.
        Then, we keep track of the first place that total was seen (a map
        by sum of each index). The partition of that index to where we are now
        represents a subarray with equal ones and zeros.
        """
        sums = {}
        sums[0] = -1 # seed the sums map or consider it as base case
        #suppose string is 01
        #sum_so_far : index
        #   0       :   -1                base case
        #   -1      :    0               when weconsider 0
        #                                now we will consider 1..present inddex will be 1..for that sum_so_far will be 0 that already occurs..so we need not change the first index..we will directly find max....(1 - (-1)) = 2(length)
        max_size = 0
        sum_so_far = 0
        #i = index
        #v = value
        #index:value   ==> enumerate....starts from i = 0 , v= nums[i] i.e. nums[0] and so on 
        
        
        for i, v in enumerate(nums):
            sum_so_far += 1 if v else -1
            if sum_so_far in sums:
                max_size = max(i - sums[sum_so_far], max_size)  #present index - first occurence 
            else:
                sums[sum_so_far] = i  #first occurence of that sum occured at which index
        
        
        return max_size