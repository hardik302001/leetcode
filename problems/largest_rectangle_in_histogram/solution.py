# very similar to : https://leetcode.com/problems/maximum-score-of-a-good-subarray/
# current element is minimim, bcz we conisder minimum height


# nse 
# pse
# monotonic stack

class Solution:
    def largestRectangleArea(self, arr):
        n = len(arr)
        next_smaller_element = [-1]*n      #monotonic inc stack, left to right
        prev_smaller_element = [-1]*n      #monotonic inc stack, right to left
    
        stack1 = []
        for i in range(n):
            while len(stack1) and arr[stack1[-1]] > arr[i]:
                next_smaller_element[stack1[-1]] = i
                stack1.pop()   
            stack1.append(i)

            
        stack2 = []
        for i in range(n-1,-1,-1):
            while len(stack2) and arr[stack2[-1]] >= arr[i]:
                prev_smaller_element[stack2[-1]] = i
                stack2.pop()
            stack2.append(i)
            
        # print(prev_smaller_element)    
        # print(next_smaller_element)
        
        ans = 0
        for i in range(n):
            if prev_smaller_element[i]== -1:
                left_diff = i - 0
            else:
                left_diff = (i - prev_smaller_element[i]) - 1
                
            if next_smaller_element[i]== -1:
                right_diff = n-1 - i
            else:
                right_diff = (next_smaller_element[i] - i) - 1
            
            # current element is minimim, bcz we consider minimum height
            
            m = arr[i]* (left_diff +  right_diff+1)
            ans = max(ans ,m)
            
        return ans