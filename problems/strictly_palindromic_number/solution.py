'''
For n = 4, base n - 2 is 100
For n >= 5, base n - 2 always is 12, as 1 * (n - 2) + 2 == n

100 and 12 are not palindromic, so always return false.
'''


class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        return False

# =========================================================
# brute force
'''
class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        def base(x, y):
            c = ''
            while x>0:
                c+=str(x%y)
                x = x//y
            return c
                
                
        for i in range(2, n-1):
            x = base(n, i)
            if x!=x[::-1]:
                return False
        return True
        
'''