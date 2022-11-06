class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []
        x  = 0
        for i in range(n-1):
            if nums[i]==nums[i+1]:
                nums[i]*=2
                nums[i+1] = 0
                
        
        for i in range(n):
            if nums[i]!=0:
                res.append(nums[i])
        while(len(res)!=n):
            res.append(0)
        return res