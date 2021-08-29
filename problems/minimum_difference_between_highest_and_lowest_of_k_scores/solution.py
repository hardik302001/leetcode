class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        if k==1:
            return 0
        m =  10000000
        for i in range(n-k+1):
            p = nums[i:i+k]
            # print(p)
            m = min(m,p[-1]-p[0])
        return m