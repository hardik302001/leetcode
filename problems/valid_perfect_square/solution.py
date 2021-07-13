class Solution:
    def isPerfectSquare(self, x: int) -> bool:
        l, r = 0, x
        while l <= r:
            mid = l + (r-l)//2
            if mid * mid==x:
                return True
            elif x < mid * mid:
                r = mid - 1
            else:
                l = mid + 1
        return False