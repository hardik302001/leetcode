class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
            res = [1] * len(nums)
    
            p = 1
            for i in range(len(nums)):
                res[i] *= p
                p *= nums[i]
            # print(res)
            p = 1
            for i in range(len(nums)-1, -1, -1):
                res[i] *= p
                p *= nums[i]
            # print(res)
            return res
        
        
#left tome, right to me
