class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        l = 0
        r = n-1
        while l<=r:
            if l==r:
                ans += nums[l]
            else:
                ans += int(str(nums[l])+ str(nums[r]))
            l+=1
            r-=1
        return ans 