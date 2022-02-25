# start giving bob from beginning , and you and alice start taking from end

class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        n  = len(piles)
        n = n//3
        
        ans = 0
        while n:
            piles.pop()                 # alice
            ans = ans + piles.pop()     # me
            n -=1
        return ans