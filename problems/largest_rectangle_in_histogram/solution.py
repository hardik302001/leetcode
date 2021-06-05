class Solution:
    
    #courtesy : apna college same title video.
    
    
    #its good to have increasing heights...
    
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)   #for safe case..bcz any of the height cant be 0..and always greater than zero..so it will a inc sequence
        stack = [-1]   #stack.top = -1
        ans = 0
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:  #decreasing height..so we need to remove..until we have again increasing heights in order again
                p= stack.pop()
                print(p)
                height = heights[p]
                width = i - stack[-1] - 1 #i i s right point  , stack[-1] is left pointer
                ans = max(ans, height * width)
            stack.append(i) #index of height array
        heights.pop()
        return ans