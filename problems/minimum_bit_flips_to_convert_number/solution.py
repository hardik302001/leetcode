class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        z = start^goal
        return bin(z)[2:].count('1')
    
    