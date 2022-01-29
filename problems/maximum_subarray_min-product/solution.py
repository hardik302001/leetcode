class Solution:
    def maxSumMinProduct(self, arr: List[int]) -> int:
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
        p = [0]*(n+1)
        for i in range(n):
            p[i+1] = p[i] + arr[i]
        
        # print(prev_smaller_element)    
        # print(next_smaller_element)
        # print(p)
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
            # print(p[i + right_diff+1] , p[i - left_diff])
            m = arr[i]* (p[i + right_diff+1] - p[i - left_diff])
            ans = max(ans ,m)
            
        return ans%1000000007