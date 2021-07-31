class Solution:

    def trap(self, height: List[int]) -> int:

        left = []   #max from left

        right = []  #max from right   (dont forget to reverse it)

        ma1 = 0

        ma2 = 0

        for i in range(len(height)):

            ma1 = max(ma1, height[i])

            ma2 = max(ma2, height[len(height)-1-i])

            left.append(ma1)

            right.append(ma2) #we are pushing max from right side at starting(left) so we need to reverse it

        print(left)

        print(right)

        print(height)

        s = 0

        for i in range(len(height)):

            s = s + min(left[i],right[len(height) - i - 1]) - height[i]      #reversing the right array while considering min

        return s

            

        
        