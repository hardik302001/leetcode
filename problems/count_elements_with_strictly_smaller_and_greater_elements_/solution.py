class Solution:
    def countElements(self , nums: List[int]) -> int:
        n = len(nums)
        mi = min(nums)
        ma = max(nums)
        
        c = 0
        for i in nums:
            if i>mi and i<ma:
                c = c + 1
        return c


'''
# O(n^2)
class Solution:
    def countElements(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        ans = 0
        for i in range(n):
            f1 = 0
            f2 = 0
            for j in range(0, i):
                if nums[j]<nums[i]:
                    f1 = 1
                    break
            for j in range(i+1, n):
                if nums[i]<nums[j]:
                    f2 = 1
                    break
            if f1 and f2:
                ans = ans + 1
        return ans
'''