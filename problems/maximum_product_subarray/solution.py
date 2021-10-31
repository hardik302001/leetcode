class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        mi = nums[0]
        ma = nums[0]
        ans = nums[0]
        for i in range(1,n):
            if(nums[i]<0):
                ma, mi = mi, ma      #swap ma , mi
            
            ma = max(nums[i],nums[i]*ma)
            mi = min(nums[i],nums[i]*mi)
           
            ans = max(ans , ma, mi)
        return ans