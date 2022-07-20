# also see: https://leetcode.com/problems/trapping-rain-water/

class Solution:
    def maxArea(self, height: List[int]) -> int:
        m = 0
        n = len(height)
        l = 0
        r = n-1
        while l<r:
            m = max(m, (r-l)*min(height[l], height[r]))
            # print((r-l)*min(height[l],height[r]))
            if height[l]==height[r]:
                l = l+1
                r = r -1
            elif height[l]>height[r]:  #bcz dec l is not efficient , bcz its already higher
                r = r -1
            elif height[l]<height[r]:      #bcz decreasing r is not efficient, bcz its already higher
                l = l+1
        return m