# see cpp solution also, 
# this is O(n),monotonic stack 


class Solution:
    def mctFromLeafValues(self, arr):
        stack =  [float('inf')]
        res = 0
        
        for num in arr:
            while stack and stack[-1] <= num:
                cur = stack.pop()
                #stack will always have atleast one thing in it after pop because inf is in there
                res += cur * min(num, stack[-1])
                
            stack.append(num)
        while len(stack) > 2:
            res += stack.pop() * stack[-1]
        
        return res