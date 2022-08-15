
# TC: O(n)
# SC: O(1)


class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        l = 0
        r = n-1
        lmax = 0
        rmax = 0
        ans = 0
        
        while l<=r:
            if height[l]<=height[r]:
                if height[l]<=lmax:
                    ans += lmax - height[l]
                else:
                    lmax = height[l]
                l+=1
            else:
                if height[r]<=rmax:
                    ans += rmax - height[r]
                else:
                    rmax = height[r]                               
                r-=1
        return ans
        




# ----------------------------------------------------------------------

'''
# see cpp for O(1) pace solution , more optimised


# TC: O(n)
# SC: O(n)


class Solution:
    def trap(self, height: List[int]) -> int:
        left = []   # max from left
        right = []  # max from right   (dont forget to reverse it)
        ma1 = 0
        ma2 = 0
        
        for i in range(len(height)):
            ma1 = max(ma1, height[i])
            ma2 = max(ma2, height[len(height)-1-i])
            left.append(ma1)
            right.append(ma2) # we are pushing max from right side at starting(left) so we need to reverse it
        print(left)
        print(right)
        print(height)
        s = 0
        for i in range(len(height)):
            s = s + min(left[i],right[len(height) - i - 1]) - height[i]      # reversing the right array while considering min
            
            
        return s

'''
    
# ----------------------------------------------------------------------

        
        