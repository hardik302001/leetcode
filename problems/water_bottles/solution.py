# brute force

class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        empty = 0
        ans = 0
        while numBottles>0:
            ans = ans + numBottles
            empty += numBottles
            numBottles = empty//numExchange
            empty = empty%numExchange
        return ans