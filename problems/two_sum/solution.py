class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        h = {}
        for i in range(len(nums)):
            if (target - nums[i]) in h:
                s,ss = i,h[target - nums[i]]
            else:
                h[nums[i]] = i
            #print(h)
        return [s,ss]
                
        