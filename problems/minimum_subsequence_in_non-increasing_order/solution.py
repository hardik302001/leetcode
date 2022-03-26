class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()
        s = sum(nums)
        ans = []
        
        p = 0
        while p<=s:
            x = nums.pop()
            ans.append(x)
            s-=x
            p+=x
        return ans
            