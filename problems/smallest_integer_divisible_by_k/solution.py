# https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/1655732/C%2B%2BJavaPython-5-lines-oror-Image-Explain-oror-Beginner-Friendly



class Solution(object):
    def smallestRepunitDivByK(self, k):
        if k % 2 == 0 or k % 5 == 0: return -1  # this trick may save a little time
        n, ans = 0, 0
        for i in range(k):  # at most k times, because 0 <= remainder < k
            ans, n = ans + 1, (n * 10 + 1) % k  # we only focus on whether to divide, so we only need to keep the remainder.
            if n == 0: return ans  # can be divisible
        return -1  # If it had not stop after k transfers, it must enter the loop, and it won't stop.
    
    
    
    
    
    
    
    
    
    
