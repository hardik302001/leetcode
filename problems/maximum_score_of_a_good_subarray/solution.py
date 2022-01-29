'''
Approach 1:
2 pointer, expand on both sides keeping index k as center and calculate max everytime!
TC:O(n)

take i=k and j=k
if(nums[i-1]<nums[j+1]) then do i-- because you will get more score this side because min will be more 
else if(nums[i-1]<= nums[j+1]) then do j++ because you will be getting good score this side

create a min variable and each time evaluate min when you are updating i or j and update ans accordingly 

edge case
1) suppose k=0 in this case you can't decrement i so you have to just increase j
2) k=n-1  in this case you can't increase j so you will decrease i only
'''
class Solution:
    def maximumScore(self, arr: List[int], k: int) -> int:
        n = len(arr)
        i = k
        j = k
        if(n==1):
            return arr[0]
    
        mn = arr[k]
        ans = 0
        while i>0 or j<(n-1):
            if i==0:
                j = j +1
            elif j==(n-1):
                i = i - 1
            elif arr[i-1]<arr[j+1]:  # so that our min will remin same
                j = j + 1
            else:
                i = i -  1
                
            mn = min(mn, arr[i], arr[j])
            ans = max(ans , mn*(j-i+1))
            # print(i, j)
        return ans
    
'''
Approach 2:
MONOTONIC STACK SOLUTION: O(n)
https://leetcode.com/problems/sum-of-subarray-minimums/
https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/

class Solution:
    def maximumScore(self, arr: List[int], k: int) -> int:
        n = len(arr)
        
        next_smaller_element = [-1]*n      #monotonic inc stack, left to right
        prev_smaller_element = [-1]*n      #monotonic inc stack, right to left
    
        stack1 = []
        for i in range(n):
            while len(stack1) and arr[stack1[-1]] >= arr[i]:
                next_smaller_element[stack1[-1]] = i
                stack1.pop()   
            stack1.append(i)

            
        stack2 = []
        for i in range(n-1,-1,-1):
            while len(stack2) and arr[stack2[-1]] > arr[i]:
                prev_smaller_element[stack2[-1]] = i
                stack2.pop()
            stack2.append(i)

        ans = 0
        print(prev_smaller_element)
        print(next_smaller_element)
        
        
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
            if (i - left_diff) <= k <= (i+right_diff):   # question ki condition
                ans = max(ans , arr[i]* (right_diff + left_diff +1 ))
        
        return ans
    
'''