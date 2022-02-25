class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)
        for i in range(1 , n , 2):
            f = nums[i-1]
            v = nums[i]
            l = [v]*f
            ans.extend(l)
        return ans