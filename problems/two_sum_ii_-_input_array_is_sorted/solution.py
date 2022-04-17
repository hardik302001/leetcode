# previous code is better

# MAP

# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:

#         ans = []
#         h = {}
#         for i in range(len(nums)):
#             if (target - nums[i]) in h:
#                 s,ss = i,h[target - nums[i]]
#                 return [ss+1,s+1]
#             else:
#                 h[nums[i]] = i
#             #print(h)
        
                
# 2 PTR

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        l, r = 0, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] == target: return (l + 1,  r + 1)
            if nums[l] + nums[r] > target: r -= 1
            else: l += 1
                
                
# BINARY SEARCH CAN ALSO BE USED,