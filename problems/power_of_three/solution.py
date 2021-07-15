class Solution(object):
    def isPowerOfThree(self, n):
        if n <= 0:
        	return False

        while n % 3 == 0:        	
        	n = n / 3

        return True if n == 1 else False