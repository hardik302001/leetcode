#lead coding by fraz yt
#MONOTONIC STACK

# also see https://leetcode.com/problems/sum-of-subarray-ranges/
# TC: O(n)



#we need next smaller element
#we need prev smaller element


class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
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
            
            # print(left_diff, right_diff)
            ans = ans + arr[i]* (left_diff +1)*( right_diff+1)
            ans = ans % 1000000007
        
        
        return ans
    
#one thing o note here is that we have strict and non strict condition in NSE and PSE respectively! Why ?
#When we have duplicate cases, then if we have both strict then we would have answer less than the expected cases, we would miss some subarray's
#if both non strict then some cases would be considered more than once

#so we do one of NSE or PSE  as strict, and other as non strict!
#you can do NSE - PSE as strict - non strict    or    NSE - PSE as non strict - strict, soesn't matter!
#we have to consider all cases only once!