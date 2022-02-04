class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        overlap = [0]*len(nums) + [0] # record the frequency for each index 
        cum = 0
        for start, end in requests: # traverse the interval will be time-consuming
            overlap[start]+=1
            overlap[end+1]-=1
        for i in range(1, len(overlap)): # we do it only once 
            overlap[i] = overlap[i-1] + overlap[i]
        # print(overlap)
        nums.sort() # sort the index and nums 
        overlap.sort()
        ans = sum([nums[i]*overlap[i+1] for i in range(len(nums))]) # multiply by index
        return ans%(10**9+7)