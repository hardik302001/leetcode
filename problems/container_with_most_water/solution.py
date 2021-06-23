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
            elif height[l]>height[r]:
                r = r -1
            elif height[l]<height[r]:
                l = l+1
        return m