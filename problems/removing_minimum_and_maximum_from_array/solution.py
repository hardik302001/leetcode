class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        mi = min(nums)
        ma = max(nums)
        n = len(nums)

        mi0 = nums.index(mi)
        ma0 = nums.index(ma)
        l = [mi0, ma0]
        l.sort()
        mi0 = l[0]
        ma0 = l[1]
        mi1 = n -1 - mi0
        ma1 = n - 1 - ma0
        
        # print(mi0, ma0, mi1 , ma1)
        
        ans = min(( ma0+1), (mi1+1), mi0 + ma1+2 )
        
        return ans