'''

1.....x-1 x x-1 x-2 x-3 x-4 ...1
_   _  _   _   _   _

n*x - sum index - sum (n-index-1) + ones<=maxSum


'''


class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        l = 1
        r = maxSum + 1
        ans = 1
        
        def check(m):
            left = min(index, m-1)
            right = min(n-index-1 , m-1)
            one = n-1-left-right
            s = m + one + left*m - left*(left+1)//2 + right*m - right*(right+1)//2
            return s<= maxSum
            
            
            
        while l<r:
            m = (l+r)//2
            if check(m):
                l = m+1
                ans = m
            else: r = m
                
        return ans