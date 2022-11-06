class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        
        n = len(nums)
        l = 0
        res = 0
        s = 0
        su = set()
        x = -1
        p = nums[:]
        p.append(0)
        for r in range(n):
            
            x+=1
            while (nums[r] in su):
                s -= nums[l]
                su.remove(nums[l])
                l+=1
            
            s+=nums[r]
            su.add(nums[r])  

            while r-l+1>k:
                su.remove(nums[l])
                s -= nums[l]
                l+=1
            
            
            if r-l+1==k:
                res = max(res , s)
                
        return res
            
            