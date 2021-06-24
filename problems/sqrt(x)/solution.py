class Solution(object):
    def mySqrt(self, x):
        l, r = 0, x
        while l <= r:
            mid = l + (r-l)//2
            if mid * mid == x:
                return mid
            elif x < mid * mid:
                r = mid - 1
            else:
                ans = mid
                l = mid + 1
        return ans
                