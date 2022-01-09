class Solution(object):
    def mySqrt(self, x):
        l, r = 0, x
        while l < r:
            mid = l + (r-l)//2
            if mid*mid==x:
                return mid   
            if x < mid * mid:
                r = mid
            else:
                l = mid + 1
        if l*l>x:
            return l-1
        else:
            return l