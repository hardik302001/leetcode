class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res1 = [1] * len(nums)
        res2 = [1] * len(nums)
        
        p = 1
        for i in range(len(nums)):
            res1[i] *= p
            p *= nums[i]
        print(res1)
        p = 1
        for i in range(len(nums)-1, -1, -1):
            res2[i] *= p
            p *= nums[i]
        res2 = res2[::-1]
        print(res2)
        
        ans = [1]*len(nums)
        ans[-1] = res1[-1]
        ans[0] = res2[-1]
        for i in range(1,len(nums)-1):
            ans[i] = res1[i]*res2[len(nums)-1-i]
            
        return ans
        
        
#  left to me, right to me
